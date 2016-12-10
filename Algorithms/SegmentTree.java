import java.util.Scanner;

public class SegmentTree {

    public static int[] segtree;
    public static int[] data;

    /*
        Method to build the array from the data array

        id: the current treenode id
        left: the left bound of the current range
        right: the right bound of the current range
     */
    public static void buildTree(int id, int left, int right) {
        //If the range contains one number, then assign the number
        if (left == right) {
            segtree[id] = data[left];
            return;
        }

        //Recursive calls to build tree
        int mid = (left + right) >> 1;
        buildTree(id * 2 + 1, left, mid);
        buildTree(id * 2 + 2, mid + 1, right);

        segtree[id] = segtree[id * 2 + 1] + segtree[id * 2 + 2];
    }

    /*
        Method to update a node in the segment tree

        id: the current treenode id
        left: the left bound of the current range
        right: the right bound of the current range
        uid: the index to update
        val: the value to update at uid
     */
    public static void updateNode(int id, int left, int right, int uid, int val) {
        //If the range is down to one element, then update it
        if (left == right) {
            segtree[id] = val;
            return;
        }

        //Recursive calls to update the children
        int mid = (left + right) >> 1;
        if (uid <= mid) {
            updateNode(id * 2 + 1, left, mid, uid, val);
        } else {
            updateNode(id * 2 + 2, mid + 1, right, uid, val);
        }

        //Update the current sum
        segtree[id] = segtree[id * 2 + 1] + segtree[id * 2 + 2];
    }

    /*
        Method to query a range sum in the segment tree

        id: the current treenode id
        left: the left bound of the current range
        right: the right bound of the current range
        qleft: the left bound of the query
        qright: the right bound of the query
     */
    public static int queryRange(int id, int left, int right, int qleft, int qright) {
        if (left > qright || right < qleft) return 0;
        if (qleft <= left && qright >= right) return segtree[id];

        int mid = (left + right) / 2;
        return queryRange(id * 2 + 1, left, mid, qleft, qright)
                + queryRange(id * 2 + 2, mid + 1, right, qleft, qright);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();

        data = new int[N];
        segtree = new int[4 * N];
        for (int i = 0; i < N; i++)
            data[i] = sc.nextInt();

        buildTree(0, 0, N - 1);

        while(Q-- != 0){
            int a = sc.nextInt();
            int b = sc.nextInt();

            System.out.println("the sum is " + queryRange(0, 0, N - 1, a, b));
        }
    }
}

