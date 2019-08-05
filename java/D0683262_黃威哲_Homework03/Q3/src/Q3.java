
public class Q3 {
	public static void main(String[] argv) {
		Marshmallow marshmallow = new Marshmallow("MarshmallowMonster",10);
		Ogre ogre = new Ogre("OgreMonster",50);
		Snake snake = new Snake("SnakeMonster",90);
		AlienPack alienPack = new AlienPack(3);
		
		alienPack.addAlien(0, marshmallow);
		alienPack.addAlien(1, ogre);
		alienPack.addAlien(2, snake);
		System.out.println("The aliens in this pack are:");
		alienPack.getAliens();
		
		System.out.println("The total damge from this Alienpack is: "+alienPack.calculateDamage());
		
		
	}
}
