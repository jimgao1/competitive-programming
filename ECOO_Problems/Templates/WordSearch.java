
public class WordSearch {
	/*------------------------------------------------------------------*/
	//finds a word in a grid and marks used
	//can be used to solve a word search if modified 
	public static boolean findWord(int r, int c, char[][] board, boolean[][] used, String word){
		//left and right
		for(int i = 0; i < r; i++){ //rows 
			for(int x = 0; x < c - word.length() + 1; x++){ //columns
				StringBuilder check = new StringBuilder("");
				for(int l = 0; l < word.length(); l++){
					check.append(board[i][x + l]);
				}
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i][x + l] = true;
					}
					return true;
				}
				check = check.reverse();
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i][x + l] = true;
					}
					return true;
				}
			}
		}
		//down and up
		for(int i = 0; i < r - word.length() + 1; i++){ //rows 
			for(int x = 0; x < c; x++){ //columns
				StringBuilder check = new StringBuilder("");
				for(int l = 0; l < word.length(); l++){
					check.append(board[i + l][x]);
				}
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i + l][x] = true;
					}
					return true;
				}
				check = check.reverse();
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i + l][x] = true;
					}
					return true;
				}
			}
		}
		//left to right diag
		for(int i = 0; i < r; i++){ //rows 
			for(int x = 0; x < c; x++){ //columns
				StringBuilder check = new StringBuilder("");
				for(int l = 0; l < word.length(); l++){
					if(i + l < r && x + l < c)
						check.append(board[i + l][x + l]);
				}
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i + l][x + l] = true;
					}
					return true;
				}
				check = check.reverse();
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i + l][x + l] = true;
					}
					return true;
				}
			}
		}
		//right to left diag
		for(int i = 0; i < r; i++){ //rows 
			for(int x = 0; x < c; x++){ //columns
				StringBuilder check = new StringBuilder("");
				for(int l = 0; l < word.length(); l++){
					if(i + l < r && x - l >= 0)
						check.append(board[i + l][x - l]);
				}
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i + l][x - l] = true;
					}
					return true;
				}
				check = check.reverse();
				if(word.equals(check.toString())){
					for(int l = 0; l < word.length(); l++){
						used[i + l][x - l] = true;
					}
					return true;
				}
			}
		}
		return false;
	}
}
