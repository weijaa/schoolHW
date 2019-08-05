
public class Vehicle {
	private String manufacturer;
	private int cylinders;
	protected Person person = new Person();
	
	Vehicle(){
		
	}
	Vehicle(String per,String str,int n){
		person.setName(per);;
		manufacturer = str;
		cylinders = n;
	}
	public void setManufacturer(String str) {
		manufacturer = str;
	}
	public String getManufacturer() {
		return manufacturer;
	}
	public void setCylinders(int n) {
		cylinders = n;
	}
	public int getCylinders() {
		return cylinders;
	}
	public String toString() {
		return "Manufacturer: "+ manufacturer+",Cylinders: "+cylinders +",Person: "+ person;
	}
	public boolean equals(Vehicle other) {
		return this.manufacturer.equals(other.manufacturer) &&
			   this.cylinders == other.cylinders &&
			   this.person.getName().equals(other.person.getName());
	}
}
