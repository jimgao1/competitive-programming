import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class POJ_1318{

    public static class Word{
        public int[] letters;
        public String actualWord;

        public Word(String w){
            this.actualWord = w;

            letters = new int[26];

            for (int i=0; i<w.length(); i++) {
                letters[w.charAt(i) - 'a'] += 1;
            }
        }

        @Override
        public boolean equals(Object n){
            Word a = (Word)(n);
            if (a == null || a.letters == null) return false;

            for (int i=0; i<26; i++)
                if (a.letters[i] != this.letters[i]) return false;

            return true;
        }


    }

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        ArrayList<Word> dictionary = new ArrayList<Word>();

        while(true){
            String word = keyboard.next();
            if (word.equals("XXXXXX")) break;

            dictionary.add(new Word(word));
        }

        while(true){
            String query = keyboard.next();

            if (query.equals("XXXXXX")) break;

            ArrayList<String> list = new ArrayList<String>();

            if (dictionary.contains(new Word(query))){
                for (int i=0; i<dictionary.size(); i++){
                    if (dictionary.get(i).equals(new Word(query)))
                        list.add(dictionary.get(i).actualWord);
                }

                Collections.sort(list);

                for (int i=0; i<list.size(); i++)
                    System.out.println(list.get(i));
            } else {
                System.out.println("NOT A VALID WORD");
            }

            System.out.println("******");
        }
    }
}
