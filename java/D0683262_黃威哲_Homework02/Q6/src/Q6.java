import java.util.Scanner;

public class Q6 {
	public static void main(String[] args) {
		Student paul = new Student();
		Student mama = new Student(5,6,8,56,90);
		Scanner input = new Scanner(System.in);
		paul.setQuizzes(input.nextInt(),input.nextInt(),input.nextInt());
		//System.out.println(paul.getQuizzes1()+""+paul.getQuizzes2()+""+paul.getQuizzes3());
		paul.setMidtermExam(input.nextInt());
		paul.setFinalExam(input.nextInt());
		System.out.printf("%.2f\n",paul.getGrade());
		System.out.println(paul.getGradeLetter());
		System.out.println(paul.toString());
		if(paul.equals(mama)) {
			System.out.println("They get the same grades");
		}else {
			System.out.println("They don't get the same grades");
		}
	}
	
}
