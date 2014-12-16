
import java.util.*;

public class POJ_3187{

    /*
            WRONG ANSWER SO BULLSHIT
     */
    
    public static class State{
        public ArrayList<Integer> currentNumbers;

        public static int target;

        public State(){
            currentNumbers = new ArrayList<Integer>();
        }

        public int getSum(){
            int sum = 0;
            for (int i=0; i<currentNumbers.size(); i++)
                sum += currentNumbers.get(i);

            return sum;
        }

        public State cloneState(){
            State newState = new State();
            newState.currentNumbers = (ArrayList<Integer>) this.currentNumbers.clone();
            newState.target = this.target;

            return newState;
        }
    }

    public static int maxNumber;
    public static int finalSum;

    public static Queue<State> searchQueue;
    public static ArrayList<State> successfulStates;

    public static int calculateSum(ArrayList<Integer> list){
        return list.get(0) + 3 * list.get(1) + 3 * list.get(2) + list.get(3);
    }

    public static boolean containState(ArrayList<Integer> list){
        for (int i=0; i<successfulStates.size(); i++){
            boolean match = true;
            for (int j=0; j<4; j++){
                if (list.get(j) != successfulStates.get(i).currentNumbers.get(j))
                    match = false;
            }
            if (match) return true;
        }

        return false;
    }

    public static boolean validCombination(ArrayList<Integer> list){
        ArrayList<Integer> knownNumbers = new ArrayList<Integer>();
        for (int i=0; i<list.size(); i++){
            if (knownNumbers.contains(list.get(i))){
                return false;
            } else {
                knownNumbers.add(list.get(i));
            }
        }

        return true;
    }

    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);

        maxNumber = keyboard.nextInt();
        finalSum = keyboard.nextInt();

        keyboard.close();

        searchQueue = new LinkedList<State>();
        successfulStates = new ArrayList<State>();

        State starting = new State();
        starting.target = finalSum;

        searchQueue.add(starting);

        while(!searchQueue.isEmpty()){
            State currentState = searchQueue.poll();

            if (currentState.currentNumbers.size() == 4 &&
                    calculateSum(currentState.currentNumbers) == finalSum){

                if (!containState(currentState.currentNumbers) && validCombination(currentState.currentNumbers))
                    successfulStates.add(currentState);

                continue;
            }

            if (currentState.currentNumbers.size() > 4) continue;

            if (finalSum - currentState.getSum() < maxNumber)
                maxNumber = finalSum - currentState.getSum();

            for (int i=1; i<maxNumber + 1; i++){
                State nextState = currentState.cloneState();
                nextState.currentNumbers.add(i);
                searchQueue.add(nextState);
            }
        }

        if (successfulStates.isEmpty()) {
            System.exit(0);
        }

        for (int i=0; i<4; i++){
            System.out.printf("%d ", successfulStates.get(0).currentNumbers.get(i));
        }

        System.out.println();
    }
}
