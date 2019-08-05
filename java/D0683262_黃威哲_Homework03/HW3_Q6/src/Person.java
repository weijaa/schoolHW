
public class Person {
	private String name;
	Person(){
		
	}
	Person(String name){
		this.name = name;
	}
	Person(Person other){
		this.name = other.name;
	}
	public void setName(String str) {
		name = str;
	}
	public String getName() {
		return name;
	}
	public String toString() {
		return "Name: "+ name;
	}
	public boolean equals(Person other) {
		return this.name == other.name;
	}
}
