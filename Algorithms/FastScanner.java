public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            try {
                br = new BufferedReader(new InputStreamReader(System.in));
            } catch (Exception ex){}
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
	}
