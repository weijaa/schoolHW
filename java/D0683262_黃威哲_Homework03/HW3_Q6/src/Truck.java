
public class Truck extends Vehicle {
	private double load;
	private int towing;
	Truck(){
		super();
	}
	Truck(String per,String str,int n,double load,int towing){
		super(per,str,n);
		this.load = load;
		this.towing = towing;
	}
	public void setLoad(double load) {
		this.load = load;
	}
	public double getLoad() {
		return this.load;
	}
	public void setTowing(int towing) {
		this.towing = towing;
	}
	public double getTowing() {
		return this.towing;
	}
	public String toString() {
		return super.toString()+",Load: "+load+",Towing: "+towing;
	}
	public boolean equals(Truck other) {
		return super.equals(other)&&
			   this.load == other.load &&
			   this.towing == other.towing;
	}
	
}
