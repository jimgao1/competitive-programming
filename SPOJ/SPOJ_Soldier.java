import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class SPOJ_Soldier {
	
	public static class Item implements Comparable<Item>{
		public int type;
		public int price;
		public int quality;
		
		public Item(int t, int p, int q){
			this.type = t;
			this.price = p;
			this.quality = q;
		}

		@Override
		public int compareTo(Item n) {
			return this.quality - n.quality;
		}

		
	}
	
	public static Map<Integer, ArrayList<Item>> items;
	
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		
		items = new HashMap<Integer, ArrayList<Item>>();
		for (int i=0; i<6; i++){
			items.put(i, new ArrayList<Item>());
		}
		
		int itemCount = keyboard.nextInt();
		int money = keyboard.nextInt();
		
		if (itemCount < 6){
			System.out.println("0");
			System.exit(0);
		}
		
		for (int i=0; i<itemCount; i++){
			int itemType = keyboard.nextInt() - 1;
			int itemPrice = keyboard.nextInt();
			int itemQuality = keyboard.nextInt();
			
			items.get(itemType).add(new Item(itemType, itemPrice, itemQuality));
		}
		
		for (int i=0; i<6; i++) if (items.get(i).isEmpty()) {
			System.out.println("0");
			System.exit(0);
		}
		for (int i=0; i<6; i++) Collections.sort(items.get(i));
		
		Item[] currentItems = new Item[6];
		
		for (int i=0; i<6; i++) currentItems[i] = items.get(i).get(0);
		
		int moneyLeft = money;
		int bottleNeck = -1;
		int minValue = -1;
		
		while(true){
			/*
			 * 	Make sure we have enough money
			 */
			
			if (moneyLeft <= 0) break;
			
			/*
			 * 	Find the bottleneck of the list of items
			 */

			minValue = Integer.MAX_VALUE;
			bottleNeck = -1;
			
			for (int i=0; i<6; i++){
				if (currentItems[i].quality < minValue){
					minValue = currentItems[i].quality;
					bottleNeck = i;
				}
			}
			
			/*
			 * 	See if we can upgrade to the next level
			 *   of the bottle neck
			 */

			if (items.get(bottleNeck).size() == 1) break;
			
			int priceGap = items.get(bottleNeck).get(1).price - items.get(bottleNeck).get(0).price;
			
			if (moneyLeft - priceGap >= 0){
				moneyLeft -= priceGap;
				items.get(bottleNeck).remove(0);
				currentItems[bottleNeck] = items.get(bottleNeck).get(0);
			}
			
		}
		
		System.out.println(minValue);

	}
}
