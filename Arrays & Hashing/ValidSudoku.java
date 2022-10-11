import java.util.*;

public class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {

        int rows = board.length;
        int cols = board[0].length;

        Set<Character> rowSet;
        Set<Character> colSet;

        // checking rows

        for (int i = 0; i < rows; i++) {
            rowSet = new HashSet<>();
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (rowSet.contains(board[i][j])) {
                    return false;
                }
                rowSet.add(board[i][j]);

            }
        }

        // check columns
        for (int i = 0; i < cols; i++) {
            colSet = new HashSet<>();
            for (int j = 0; j < rows; j++) {
                if (board[j][i] == '.') {
                    continue;
                }

                if (colSet.contains(board[j][i])) {
                    return false;
                }
                colSet.add(board[j][i]);
            }
        }

        // checking 3x3 sub-section
        for (int i = 0; i < rows; i += 3) {
            for (int j = 0; j < cols; j += 3) {
                if (!checkSubSect(i, j, board)) {
                    return false;
                }
            }
        }

        return true;
    }

    public static boolean checkSubSect(int idxI, int idxJ, char[][] board) {
        int rows = idxI + 3;
        int cols = idxJ + 3;

        Set<Character> sectionSet = new HashSet<>();

        for (int i = idxI; i < rows; i++) {

            for (int j = idxJ; j < cols; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (sectionSet.contains(board[i][j])) {
                    return false;
                }

                sectionSet.add(board[i][j]);
            }
        }

        return true;
    }
}
