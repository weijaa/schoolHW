
public class Student {
	
	private int[] quizzes = new int[3];
	private int midtermExam, finalExam;
	private double grade ;
	private char gradeLetter;
	public Student() {
		
	}
	public Student(int quizzes1, int quizzes2, int quizzes3 ,int midtermExam, int finalExam){
		this.quizzes[0] = quizzes1;
		this.quizzes[1] = quizzes2;
		this.quizzes[2] = quizzes3;
		this.midtermExam = midtermExam;
		this.finalExam = finalExam;
	}
	
	public void setQuizzes(int quizzes1, int quizzes2, int quizzes3) {
		if(quizzes1 <= 10 && quizzes1 >=0) {
			this.quizzes[0] = quizzes1;
		}
		if(quizzes2 <= 10 && quizzes2 >=0) {
			this.quizzes[1] = quizzes2;
		}
		if(quizzes3 <= 10 && quizzes3 >=0) {
			this.quizzes[2] = quizzes3;
		}
	}
	public void setMidtermExam(int midtermWxam) {
		if(midtermExam >= 0 && midtermExam <= 100) {
			this.midtermExam = midtermWxam;
		}
	}
	public void setFinalExam(int finalExam) {
		if(finalExam >= 0 && finalExam <= 100) {
			this.finalExam = finalExam;
		}
	}
	public int getQuizzes1() {
		return quizzes[0];
	}
	public int getQuizzes2() {
		return quizzes[1];
	}
	public int getQuizzes3() {
		return quizzes[2];
	}
	public int getMidtermExam() {
		return midtermExam;
	}
	public int getFinalExam() {
		return finalExam;
	}
	public double getGrade() {
		
		grade = (double)(quizzes[0]+quizzes[1]+quizzes[2])/3*10*0.25 + (double)midtermExam*0.35 + (double)finalExam*0.4;
		return grade;
	}
	public char getGradeLetter() {
		grade = (double)(quizzes[0]+quizzes[1]+quizzes[2])/3*10*0.25 + (double)midtermExam*0.35 + (double)finalExam*0.4;
		if( grade >= 90) {
			gradeLetter = 'A';
			return gradeLetter;
		}else if(grade >= 80) {
			gradeLetter = 'B';
			return gradeLetter;
		}else if(grade >= 70) {
			gradeLetter = 'C';
			return gradeLetter;
		}else if(grade >= 60) {
			gradeLetter = 'D';
			return gradeLetter;
		}else {
			gradeLetter = 'F';
			return gradeLetter;
		}
		
	}
	public boolean equals(Student other) {
		return quizzes[0] == other.quizzes[0] && quizzes[1] == other.quizzes[1] && quizzes[2] == other.quizzes[2] && midtermExam == other.midtermExam && finalExam == other.finalExam;    
	}
	public String toString() {
		return "quizzes1: " + quizzes[0] +" quizzes2: " + quizzes[1] + " quizzes3: " + quizzes[2] + " midtermExam: "+ midtermExam + " finalExam: "+ finalExam;
	}
}
