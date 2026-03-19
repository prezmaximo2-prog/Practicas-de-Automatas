import java.nio.file.*;
import java.util.regex.*;
import java.util.*;

public class JavaLexer {
    public static void main(String[] args) throws Exception {
        // Lectura directa del archivo
        String src = String.join("\n", Files.readAllLines(Paths.get("/home/maximo/IdeaProjects/JavaLexer/src/Ejemplo.java")));

        // Un solo patrón gigante con TODOS los grupos que tiene tu código limpio
        Pattern p = Pattern.compile(
                "(?<CMTLINE>//[^\\n]*)|" +
                        "(?<CMTBLK>/\\*[\\s\\S]*?\\*/)|" +
                        "(?<STR>\"([^\"\\\\]|\\\\.)*\")|" +
                        "(?<CHR>'([^'\\\\]|\\\\.)')|" +
                        "(?<DEC>[0-9][0-9_]*\\.[0-9][0-9_]*([eE][+-]?[0-9]+)?[fFdD]?)|" +
                        "(?<INT>0|[1-9][0-9_]*[lL]?)|" +
                        "(?<KW>\\b(abstract|assert|boolean|break|byte|case|catch|char|class|const|continue|default|do|double|else|enum|extends|final|finally|float|for|goto|if|implements|import|instanceof|int|interface|long|native|new|package|private|protected|public|return|short|static|strictfp|super|switch|synchronized|this|throw|throws|transient|try|void|volatile|while|true|false|null|var|yield|record)\\b)|" +
                        "(?<ID>[a-zA-Z_$][a-zA-Z0-9_$]*)|" +
                        "(?<OP>==|!=|<=|>=|&&|\\|\\||<<|>>|\\+\\+|--|[+\\-*/%<>=!&|^~])|" +
                        "(?<SEP>[(){}\\[\\];,])|" +
                        "(?<SPC>[ \\t\\r\\n]+)"
        );

        Matcher m = p.matcher(src);
        int line = 1, col = 1, pos = 0;

        System.out.println("=== REPORTE DE ANÁLISIS (VERSIÓN LINEAL) ===");

        while (m.find()) {
            // FASE 3: Manejo de errores (Panic Recovery) incrustado
            if (m.start() > pos) {
                String err = src.substring(pos, m.start());
                System.err.printf("[Ln: %04d, Col: %03d] -> NO_RECONOCIDO         | %s%n", line, col, err);
                // Actualizar coordenadas del error
                for(char c : err.toCharArray()) { if(c == '\n') { line++; col = 1; } else col++; }
            }

            String val = m.group();
            String tipo = "";

            // IF-ELSE GIGANTE para determinar el tipo (En lugar de usar el Enum)
            if (m.group("CMTLINE") != null) tipo = "COMENTARIO_LINEA";
            else if (m.group("CMTBLK") != null) tipo = "COMENTARIO_BLOQUE";
            else if (m.group("STR") != null) tipo = "TEXTO_LITERAL";
            else if (m.group("CHR") != null) tipo = "CARACTER_LITERAL";
            else if (m.group("DEC") != null) tipo = "DECIMAL_LITERAL";
            else if (m.group("INT") != null) tipo = "ENTERO_LITERAL";
            else if (m.group("KW") != null) tipo = "PALABRA_RESERVADA";
            else if (m.group("ID") != null) tipo = "IDENTIFICADOR";
            else if (m.group("OP") != null) tipo = "SIMBOLO_OPERADOR";
            else if (m.group("SEP") != null) tipo = "SIMBOLO_SEPARADOR";

            // Si no es espacio, imprimir (Fase 2)
            if (m.group("SPC") == null) {
                System.out.printf("[Ln: %04d, Col: %03d] -> %-20s | %s%n", line, col, tipo, val);
            }

            // Actualizar línea y columna carácter por carácter (Lógica manual)
            for (char c : val.toCharArray()) {
                if (c == '\n') { line++; col = 1; }
                else col++;
            }
            pos = m.end();
        }
    }
}
