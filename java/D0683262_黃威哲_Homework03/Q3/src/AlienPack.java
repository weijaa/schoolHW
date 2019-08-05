
public class AlienPack  {
	private Alien[] x;
	AlienPack(int num){
		x = new Alien[num];
	}
	public void addAlien(int index,Alien other) {
		x[index] =  other;
	}
	public void getAliens() {
		for(int i=0; i<x.length; i++) {
			if(x[i] instanceof Ogre) {
				System.out.printf("Name: %-20s Health: %2d Damage: 6\n",x[i].getName(),x[i].getHealth());
			}else if(x[i] instanceof Marshmallow) {
				System.out.printf("Name: %-20s Health: %2d Damage: 1\n",x[i].getName(),x[i].getHealth());
			}else {
				System.out.printf("Name: %-20s Health: %2d Damage: 10\n",x[i].getName(),x[i].getHealth());
			}
		}
	}
	public int calculateDamage() {
		int num= 0;
		for(int i =0; i<x.length; i++) {
			if(x[i] instanceof Ogre) {
				num+=6;
			}else if(x[i] instanceof Marshmallow) {
				num+=1;
			}else {
				num+=10;
			}
		}
		return num;
	}
}
