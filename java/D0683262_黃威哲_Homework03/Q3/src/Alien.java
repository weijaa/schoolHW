
public class Alien {
	private int health;
	private String name;
	public Alien(String name, int health) {
		this.health = health;
		this.name = name;
	}
	public Alien() {
	
	}
	public int getHealth() {
		return this.health;
	}
	public void setHealth(int health) {
		this.health = health;
	}
	public String getName() {
		return this.name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String toString() {
		return "Name: "+ this.name+ ", Health: "+ health;
	}
}

