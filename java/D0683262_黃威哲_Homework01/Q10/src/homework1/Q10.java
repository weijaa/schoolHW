package homework1;
import java.util.Scanner;
public class Q10 {
	
	public static void main (String[] args) {
		Scanner input  = new Scanner(System.in);
		int[] quantity = new int[3];
		
		String[] name = new String[3];
		
		float[] price = new float[3];
		
		float[] total = new float[3];
		float subtotal = 0 ,tax = 0;
		int i = 0;
		
		for(i=0;i<3;i++) {
			System.out.println("Input name of item " + (i+1));
			name[i] = input.nextLine();
			System.out.println("Input quantity of item " + (i+1));
			quantity[i] = input.nextInt();
			System.out.println("Input price of item " + (i+1));
			price[i] = input.nextFloat();
			input.nextLine();
			total[i] = quantity[i] * price[i];
		}
		System.out.println("Your bill:");
		System.out.println("");
		System.out.println("Item                          Quantity  Price     Total     ");
		for(i=0;i<3;i++) {
			System.out.printf("%-30s%-10d%-10.2f%-10.2f\n",name[i],quantity[i],price[i],total[i]);
			subtotal = subtotal + total[i];
		}
		tax = subtotal * (float)0.0625;
		System.out.printf("Subtotal%47.2f\n",subtotal);
		System.out.printf("6.25%% sales tax%40.2f\n",tax);
		System.out.printf("Total%50.2f", subtotal+tax);
	}
}
