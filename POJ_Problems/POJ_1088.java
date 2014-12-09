import java.util.Scanner;

public class POJ_1088 {
        
        /*
         *   NOT COMPLETE
         */
        
        public static char[][] map;
        
        public static int sizeX;
        public static int sizeY;
        
        public static int maxLength;
        
        public static int getElement(int x, int y){
                try{
                        return map[x][y];
                } catch (Exception ex){
                        return -1;
                }
        }
        
        public static void search(int x, int y, int steps){
                if (x < 0 || x >= sizeX) return;
                if (y < 0 || y >= sizeY) return;
                if (steps > sizeX * sizeY) return;
                
                int current = getElement(x, y);
                
                int up = getElement(x, y - 1);
                int down = getElement(x, y + 1);
                int left = getElement(x - 1, y);
                int right = getElement(x + 1, y);
                
                if (up != -1 && up < current) search(x, y - 1, steps + 1);
                if (down != -1 && down < current) search(x, y + 1, steps + 1);
                if (left != -1 && left < current) search(x - 1, y, steps + 1);
                if (right != -1 && right < current) search(x + 1, y, steps + 1);
                
                return;
        }
        
        public static void main(String[] args){
                Scanner keyboard = new Scanner(System.in);
                
                sizeY = keyboard.nextInt();
                sizeX = keyboard.nextInt();
                
                keyboard.nextLine();
                
                map = new char[sizeX][sizeY];
                
                for (int i=0; i<sizeY; i++){
                        String line = keyboard.nextLine();
                        for (int j=0; j<sizeX; j++){
                                map[j][i] = line.charAt(j);
                        }
                }
        }
}
