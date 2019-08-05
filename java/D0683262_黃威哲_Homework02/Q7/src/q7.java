
public class q7 {
	public static void main(String[] args) {
		Temperature a = new Temperature('F',32);
		Temperature b = new Temperature('C',0);
		if(a.equals(b)) {
			System.out.println("Equals degree");
		}else if(a.greater(b)) {
			System.out.println("Greater degree");
		}else if(a.less(b)) {
			System.out.println("Less degree");
		}
		System.out.println(a.toString());
	}
}
