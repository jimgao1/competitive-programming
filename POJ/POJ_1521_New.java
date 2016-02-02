import java.util.PriorityQueue;
import java.util.Scanner;

public class POJ_1521_New {

    public static class TreeNode implements Comparable<TreeNode>{
        public char value;
        public int freq;

        TreeNode left, right;

        public TreeNode(){}
        public TreeNode(char v, int f) {
            this.value = v;
            this.freq = f;
            this.left = null;
            this.right = null;
        }
        public TreeNode(TreeNode l, TreeNode r) {
            this.left = l;
            this.right = r;
            this.freq = l.freq + r.freq;
        }

        @Override
        public int compareTo(TreeNode node) {
            return this.freq - node.freq;
        }
    }

    public static int letterFreq[];
    public static String[] huffman;

    public static PriorityQueue<TreeNode> nodes;

    public static void dfs(TreeNode current, String coding){
        if (current.left == null || current.right == null){
            huffman[current.value] = coding;
        } else {
            dfs(current.left, coding + "0");
            dfs(current.right, coding + "1");
        }
    }

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        while(true) {
            letterFreq = new int[128];
            huffman = new String[128];
            nodes = new PriorityQueue<TreeNode>();

            String str = keyboard.nextLine();

            if (str.equals("END")) break;

            for (char c : str.toCharArray()) {
                letterFreq[c]++;
            }

            for (int i = 0; i < 128; i++) {
                if ((letterFreq[i] != 0)) {
                    nodes.add(new TreeNode((char) i, letterFreq[i]));

                }
            }

            while (nodes.size() > 1) {
                TreeNode nodeA = nodes.poll();
                TreeNode nodeB = nodes.poll();

                nodes.add(new TreeNode(nodeA, nodeB));
            }

            dfs(nodes.peek(), "");

            int totalLength = 0;

            for (char c : str.toCharArray()) {
                totalLength += huffman[c].length();
            }

            if (totalLength == 0) totalLength = str.length();

            System.out.print(str.length() * 8 + " ");
            System.out.print(totalLength + " ");
            System.out.printf("%.1f\n", (double) (str.length() * 8) / totalLength);
        }
    }
}
