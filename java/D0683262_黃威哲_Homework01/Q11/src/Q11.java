import java.util.Scanner;
import java.text.DecimalFormat;
public class Q11 {


	public static void main(String[] argv) {
		String[] name = new String[3];
		int[] grade = new int[3];
		int[] gradeAll = new int[3];
		int gradeSum = 0;
		int gradeAllSum = 0;
		double percent;
		Scanner s = new Scanner(System.in);
		int i;
		for(i = 0; i < 3; i++) {
			System.out.println("Name of exercise "+ (i+1) + ":");
			name[i] = s.nextLine();
			System.out.println("Score received for exercise "+ (i+1) + ":");
			grade[i] = s.nextInt();
			System.out.println("Total points possible for exercise " + (i+1) + ":");
			gradeAll[i] = s.nextInt();
			s.nextLine();
		}
		System.out.println("Exercise            Score     Total Possible");
		for(i = 0; i < 3; i++) {
			System.out.printf("%-20s%-10d%-10d\n",name[i],grade[i],gradeAll[i]);
			gradeSum = gradeSum + grade[i];
			gradeAllSum = gradeAllSum + gradeAll[i];
		}
		System.out.printf("Total               %-10d%-10d\n",gradeSum,gradeAllSum);
		percent = (double)gradeSum/(double)gradeAllSum;
		DecimalFormat df = new DecimalFormat("#####0.00%");
		System.out.println("Your total is " + gradeSum + " out of "+ gradeAllSum + ", or " + df.format(percent));
	}
}
