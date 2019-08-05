import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Q6 {
	public static void main(String[] args) {
			Game g = new shot();
			g.play();
			/*shot a = new shot(1);
			a.initialize();
			a.startPlay();*/
	}
}
abstract class Game {
	 
	 final void play() {
	   initialize();
	   while(!endGame()) {
		   startPlay();
		   reward();
		   buy();
	   }
	   result();
	 }

	 

	 abstract void initialize();
	 abstract void startPlay();
	 abstract void result();
	 abstract boolean endGame();
	 abstract void reward();
	 abstract void buy();

	 }
	abstract class entity {
		 String entity_name;
		 entity() {
		}
		 
	}



	class racecar extends Game {
	 
	 class car extends entity{
	  String car_name;
	  double speed;
	  double Acceleration;
	  double weight;
	  int money;
	  equipment equipment;
	  int carpoint=0;
	  
	  public car(String car_name,double speed,double Acceleration,double weight,int money,int carpoint) {
	   this.car_name=car_name;
	   this.speed=speed;
	   this.Acceleration=Acceleration;
	   this.weight=weight;
	   this.money=money;
	   this.carpoint=carpoint;
	  } 
	 }
	 
	 
	 class equipment {
	  String equ_name;
	  double speed;
	  double Acceleration;
	  int cost;
	  double weight;
	  
	  public equipment(String equ_name,double speed,double Acceleration,double weight,int cost) {
	   this.equ_name=equ_name;
	   this.speed=speed;
	   this.Acceleration=Acceleration;
	   this.weight=weight;
	   this.cost=cost;
	  } 
	 }
	 
	 

	 
	 
	 car car1 = new car("ferrari",8.1111,3,6,0,0);
	 car car2 = new car("porsche",4.1111,2,10,0,0);
	 car car3 = new car("tesla",5.1111,3.2,7,0,0);
	 equipment equ1 = new equipment("equ1",2.4,1.2,2.45,800);
	 equipment equ2 = new equipment("equ2",2.4,1.2,2.45,800);
	 equipment equ3 = new equipment("equ3",2.4,1.2,2.45,800);
	 equipment equ4 = new equipment("equ4",2.4,1.2,2.45,800);
	 equipment equ5 = new equipment("equ5",2.4,1.2,2.45,800);
	 
	 car p;
	 car c;
	 
	 int distance=150;
	 int time;
	 private Scanner input;
	 
	 @Override
	 
	 void initialize() {
	  System.out.println("please select your car: "+'"'+ car1.car_name +'"'+" or "+'"'+car2.car_name+'"'+" or "+ '"' +car3.car_name+'"');
	  input = new Scanner(System.in);
	  int select_car =0;
	  do {
	   select_car = input.nextInt();
	   if(select_car>3) {
	    System.out.println("please enter the number 1 or 2 or 3");
	   }
	  }while(select_car>3);
	  // TODO Auto-generated method stub
	  
	   switch(select_car) {
	   case(1):
	    p=car1;
	    break;
	   case(2):
	    p=car2;
	    break;
	   case(3):
	    p=car3;
	    break;
	   }
	   System.out.println("Your car is " + p.car_name);
	   
	   int ran = (int)(Math.random()*3)+1;
	   do {
		   
	   switch(ran = (int)(Math.random()*3)+1) {
	   
	   case(1):
	    c=car1;
	   break;
	    
	   case(2):
	    c=car2;
	   break;
	   
	   case(3):
	    c=car3;
	   break;
	   }
	   }while(ran==select_car);
	   System.out.println("Computer's car is " + c.car_name);
	   }
	 
	 @Override
	 void startPlay() {
	  // TODO Auto-generated method stub
	  String player = "";
	  String computer = "";
	  String player_line="";
	  String computer_line="";
	  double time=0;
	  int plaer_distance=0;
	  int computer_distance=0;
	  double p_speed;
	  double c_speed;
	  p_speed=p.speed-p.weight*0.1;
	  c_speed=c.speed-c.weight*0.1;
	  
	  if(p.carpoint+c.carpoint==0) {
		  System.out.println("-------------------------------------------------------------------------game1-----------------------------------------------------------------------------");
	  }
	  else if (p.carpoint+c.carpoint==1) {
		  System.out.println("-------------------------------------------------------------------------game2-----------------------------------------------------------------------------");
	  }
	  else if (p.carpoint+c.carpoint==2) {
		  System.out.println("-------------------------------------------------------------------------game3-----------------------------------------------------------------------------");
	  }
	  do {
		  
		 
			  
	   p_speed+=p.Acceleration*time;
	   c_speed+=c.Acceleration*time;
	   player+=(p.car_name);
	   computer+=c.car_name;
	   if(player.length()>distance) {
	    player="";
	    for(int j=0;j<distance-p.car_name.length();j++) {
	     player+=" ";
	    }
	    player+=p.car_name;
	    plaer_distance=distance;
	   }
	   if(computer.length()>distance) {
	    computer="";
	    for(int j=0;j<distance-c.car_name.length();j++) {
	     computer+=" ";
	    }
	    computer+=c.car_name;
	    computer_distance=distance;
	   }
	   
	   for(int j=0;j<distance-player.length();j++) {
	    player_line+=" ";
	   }
	   for(int j=0;j<distance-computer.length();j++) {
	    computer_line+=" ";
	   }
	   
	   player_line+="||";
	   computer_line+="||";
	   System.out.print(player);
	   System.out.println(player_line);
	   System.out.print(computer);
	   System.out.println(computer_line);
	   
	   
	   for(int j=0;j<p_speed;j++) {
	    player+=" ";
	   }
	   for(int j=0;j<c_speed;j++) {
	    computer+=" ";
	   }
	   
	   player=player.replace(p.car_name, "");
	   computer=computer.replace(c.car_name, "");
	   player_line="";
	   computer_line="";
	   time+=1;
	   /*try {
	    TimeUnit.SECONDS.sleep(1);
	   } catch (InterruptedException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
	   }*/
	   for(int k=0;k<distance;k++) {
		    System.out.print("-");
		   }
		   System.out.print("||\n");
	  }while(distance-plaer_distance>0 && distance-computer_distance>0);
	  matchset(plaer_distance,computer_distance);
	 }
	 
	 void matchset(int player,int computer) {
	  if(player>computer) {
	   p.carpoint++;
	   System.out.println("========================================================================================================================================================");
	   System.out.println("===========================================================      The winner is \"player\"      ===========================================================");
	   System.out.println("========================================================================================================================================================");
	 
	  }
	  else if (player==computer) {

	   System.out.println("========================================================================================================================================================");
	   System.out.println("===================================================================        Draw      ===================================================================");
	   System.out.println("========================================================================================================================================================");

	  }
	  else {
	   c.carpoint++;
	   System.out.println("========================================================================================================================================================");
	   System.out.println("========================================================      The winner is \"computer\"      ==========================================================");
	   System.out.println("========================================================================================================================================================");
	  }
	 }

	 @Override
	 void reward() {
		if(c.carpoint==2||p.carpoint==2) {
			
		}
		 
		else { 
			if(p.speed-p.weight*0.1+p.Acceleration>c.speed-c.weight*0.1+c.Acceleration) {
		  System.out.println("Player get money: $1000");
		   System.out.println("Computer get money: $600");
	   p.money+=1000;
	   c.money+=600;
	  }
	  else if(p.speed-p.weight*0.1+p.Acceleration==c.speed-c.weight*0.1+c.Acceleration) {
		  System.out.println("Player get money: $800");
		   System.out.println("Computer get money: $800");
	   p.money+=800;
	   c.money+=800;
	  }
	  else {
		  System.out.println("Player get money: $600");
		   System.out.println("Computer get money: $1000");
	   p.money+=600;
	   c.money+=1000;
	  }
	 }
	 }
	 boolean enoughPay(int money,int cost) {
	  if(money>=cost) {
	   
	   return true;
	  }
	  else {
	   return false;
	  }
	 }
	 void useEqu(double speed,double Acceleration,double weight) {
		 p.speed+=speed;
	  	p.Acceleration+=Acceleration;
	  	p.weight+=weight;
	 }
	@Override
	 void buy() {
	// TODO Auto-generated method stub
	if(c.carpoint==2||p.carpoint==2) {
			
		}
	else {				
	 System.out.println("==================================");
	 System.out.println("========    The shop     =========");
	 System.out.println("==================================");
	 System.out.println("Player's money: $" + p.money);
	 System.out.println("Computer's money: $" + c.money);
	 System.out.println("==========================");
	 System.out.println(equ1.equ_name+": $"+equ1.cost);
	 System.out.println(equ2.equ_name+": $"+equ2.cost);
	 System.out.println(equ3.equ_name+": $"+equ3.cost);
	 System.out.println(equ4.equ_name+": $"+equ4.cost);
	 System.out.println(equ5.equ_name+": $"+equ5.cost);
	 System.out.println("==========================");
	 input = new Scanner(System.in);
	 int select_equ=0;
	 do {
	  System.out.println("Please select your equipment to buy: "+'"'+equ1.equ_name+'"'+" or "+'"'+equ2.equ_name+" or "+'"'+equ3.equ_name+'"'+" or "+equ4.equ_name+" or "+'"'+equ5.equ_name+'"');
	  System.out.println("if you want to leave,please enter "+'"'+6+'"');
	  select_equ=input.nextInt();
	 switch(select_equ) {
	  case(1):
	   if(enoughPay(p.money,equ1.cost)) {
	    System.out.println("You buy the "+equ1.equ_name);
	    System.out.println("==========================");
	    useEqu(equ1.speed,equ1.Acceleration,equ1.weight);
	    p.money-=equ1.cost;
	    break;
	   }
	   else {
	    System.out.println("You can't buy the "+equ1.equ_name);
	    System.out.println("==========================");
	    break;
	   }
	   
	  case(2):
	   if(enoughPay(p.money,equ2.cost)) {
	    System.out.println("You buy the "+equ2.equ_name);
	    System.out.println("==========================");
	    p.money-=equ2.cost;
	    useEqu(equ2.speed,equ2.Acceleration,equ2.weight);
	    break;
	   }
	   else {
	    System.out.println("You can't buy the "+equ2.equ_name);
	    System.out.println("==========================");
	    break;
	   }
	   
	  case(3):
	   if(enoughPay(p.money,equ3.cost)) {
	    System.out.println("You buy the "+equ3.equ_name);
	    System.out.println("==========================");
	    useEqu(equ3.speed,equ3.Acceleration,equ3.weight);
	    p.money-=equ3.cost;
	    break;
	   }
	   else {
	    System.out.println("You can't buy the "+equ3.equ_name);
	    System.out.println("==========================");
	    break;
	    
	   }
	  //***not completed
	  case(4):
	   if(enoughPay(p.money,equ4.cost)) {
	    System.out.println("You buy the "+equ4.equ_name);
	    System.out.println("==========================");
	    useEqu(equ4.speed,equ4.Acceleration,equ4.weight);
	    p.money-=equ4.cost;
	    break;
	   }
	   else {
	    System.out.println("You can't buy the "+equ4.equ_name);
	    System.out.println("==========================");
	    break;
	   }
	  //***not completed
	  case(5):
	   if(enoughPay(p.money,equ5.cost)) {
	    System.out.println("You buy the "+equ5.equ_name);
	    System.out.println("==========================");
	    useEqu(equ5.speed,equ5.Acceleration,equ5.weight);
	    p.money-=equ5.cost;
	    break;
	   }
	   else {
	    System.out.println("You can't buy the "+equ5.equ_name);
	    System.out.println("==========================");
	    break;
	   }
	  
	  }
	 }while(select_equ!=6);
	  int random = (int)(Math.random()*5)+1;
	 do {

	  switch(random) {
	  case(1):
	   if(enoughPay(c.money,equ1.cost)) {
	 System.out.println("Computer buy the "+equ1.equ_name);
	    useEqu(equ1.speed,equ1.Acceleration,equ1.weight);
	    c.money-=equ1.cost;
	    break;
	   }
	   else {
	    break;
	   }
	   
	  case(2):
	   if(enoughPay(c.money,equ2.cost)) {
	 System.out.println("Computer buy the "+equ2.equ_name);
	    useEqu(equ2.speed,equ2.Acceleration,equ2.weight);
	    c.money-=equ2.cost;
	    break;
	   }
	   else {
	    break;
	   }
	   
	  case(3):
	   if(enoughPay(c.money,equ3.cost)) {
		   System.out.println("Computer buy the "+equ3.equ_name);
		    useEqu(equ2.speed,equ2.Acceleration,equ3.weight);
		    c.money-=equ2.cost;
		    break;
		   }
		   else {
		    break;
		   }
	  
	 case(4):
		   if(enoughPay(c.money,equ4.cost)) {
			   System.out.println("Computer buy the "+equ4.equ_name);
			    useEqu(equ2.speed,equ2.Acceleration,equ4.weight);
			    c.money-=equ2.cost;
			    break;
			   }
			   else {
			    break;
			   }
		  
	case(5):
		   if(enoughPay(c.money,equ5.cost)) {
			   System.out.println("Computer buy the "+equ5.equ_name);
			    useEqu(equ2.speed,equ2.Acceleration,equ5.weight);
			    c.money-=equ2.cost;
			    break;
			   }
			   else {
			    break;
			   }
		  }
	 }while(enoughPay(c.money,equ1.cost)||enoughPay(c.money,equ2.cost)||enoughPay(c.money,equ3.cost)||enoughPay(c.money,equ4.cost)||enoughPay(c.money,equ5.cost));
	}
	}
	@Override
	void result() {
		// TODO Auto-generated method stub
		 System.out.println("Game Over");
		 if(c.carpoint>p.carpoint) {
			 System.out.println("the winer is "+'"'+"computer"+'"');
		 }
		 else if(c.carpoint<p.carpoint) {
			 System.out.println("the winer is "+'"'+"player"+'"');
		 }
		 else {
			 System.out.println("no winner");
		 }
	}

	@Override
	boolean endGame() {
		  if(c.carpoint==2||p.carpoint==2) {
		   return true;
		  }
		  return false;
		// TODO Auto-generated method stub

		  }
}
class shot extends Game {
	
	 int distance=120;
	 int time;
	 int select_entity;
	 private Scanner input;
	class shoter extends entity{
		String player_name;
		int speed;
		int Acceleration;
		int money;
		equipment equipment;
		int shotPoint = 0;
		int ans=0; //-1 = lose and 1 = win
		public shoter(String player_name,int speed,int Acceleration,int money,int shotPoint) {
			   this.player_name=player_name;
			   this.speed = speed;
			   this.Acceleration=Acceleration;
			   this.money=money;
			   this.shotPoint=shotPoint;
			  } 
	}
	class equipment {
		  String equ_name;
		  double speed;
		  double Acceleration;
		  int cost;
		  
		  public equipment(String equ_name,int speed,int Acceleration,int cost) {
			   this.equ_name=equ_name;
			   this.speed=speed;
			   this.Acceleration=Acceleration;
			   this.cost=cost;
			  } 
	}
	
	shoter shoter1 = new shoter("Amy",2,3,0,0);
	shoter shoter2 = new shoter("Kobe",3,2,0,0);
	shoter shoter3 = new shoter("Rose",4,1,0,0);
	equipment equ1 = new equipment("Pistol",1,0,200);
	equipment equ2 = new equipment("Machine gun",0,1,300);
	equipment equ3 = new equipment("Laser gun",1,1,500);
	shoter p,c;
	
	 @Override
	void initialize() {
	// TODO Auto-generated method stub
		 System.out.println("please select your car: "+"1."+ shoter1.player_name +", 2."+shoter2.player_name+", 3." +shoter3.player_name);
		  input = new Scanner(System.in);
		  int select_player =0;
		  do {
		   select_player = input.nextInt();
		   if(select_player>3) {
		    System.out.println("please enter the number 1 or 2 or 3");
		   }
		  }while(select_player>3);
		  
		 int ran = (int)(Math.random()*3)+1;
		 switch(select_player) {
		   case(1):
			    p = shoter1;
			    break;
		   case(2):
			    p = shoter2;
		    	break;
		    case(3):
		    	p = shoter3;
		    	break;
		 }
		   
		 switch(ran) {
		   case(1):
			    c = shoter1;
			    break;
		   case(2):
			    c = shoter2;
		    	break;
		    case(3):
		    	c = shoter3;
		    	break;
		 }
		 System.out.println("Your shoter is " + p.player_name);
		 System.out.println("computer's shoter is " + c.player_name);
	}
	
	
	@Override
	void result() {
	// TODO Auto-generated method stub
		System.out.println("Game Over");
		 if(c.shotPoint>p.shotPoint) {
			 System.out.println("the winer is "+'"'+"computer"+'"');
		 }
		 else if(c.shotPoint<p.shotPoint) {
			 System.out.println("the winer is "+'"'+"player"+'"');
		 }
		 else {
			 System.out.println("no winner");
		 }
	}
	
	@Override
	boolean endGame() {
		  if(c.shotPoint==2||p.shotPoint==2) {
		   return true;
		  }
		  return false;
		// TODO Auto-generated method stub

		  }
	
	@Override
	void reward() {
	// TODO Auto-generated method stub
		if(c.shotPoint==2||p.shotPoint==2) {
			
		}
		else{ 
			if(p.ans > c.ans) {
				System.out.println("Player get money: $300");
				System.out.println("Computer get money: $200");
				p.money+=300;
				c.money+=200;
			}
			else if(p.ans == c.ans) {
				p.money+=100;
				c.money+=100;
				System.out.println("Player get money: $100");
				System.out.println("Computer get money: $100");
			}
			else {
				System.out.println("Player get money: $200");
				System.out.println("Computer get money: $300");
				p.money+=200;
				c.money+=300;
			}
		}
	 }
	 boolean enoughPay(int money,int cost) {
	  if(money>=cost) {
	   
	   return true;
	  }
	  else {
	   return false;
	  }
	 }
	 void useEqu(double speed,double Acceleration) {
	  p.speed+=speed;
	  p.Acceleration+=Acceleration;
	}
	
	@Override
	void buy() {
	// TODO Auto-generated method stub
		if(c.shotPoint==2||p.shotPoint==2) {
			
		}
		else {				
		 System.out.println("==================================");
		 System.out.println("========    The shop     =========");
		 System.out.println("==================================");
		 System.out.println("Player's money: $" + p.money);
		 System.out.println("Computer's money: $" + c.money);
		 System.out.println("==========================");
		 System.out.println(equ1.equ_name+": $"+equ1.cost);
		 System.out.println(equ2.equ_name+": $"+equ2.cost);
		 System.out.println(equ3.equ_name+": $"+equ3.cost);
		 System.out.println("==========================");
		 input = new Scanner(System.in);
		 int select_equ=0;
		 do {
			 System.out.println("Please select your equipment to buy:"+" 1." +equ1.equ_name+ ", 2."+equ2.equ_name+", 3."+equ3.equ_name+ ", 4.exit");
			 select_equ=input.nextInt();
		 switch(select_equ) {
		  case(1):
		   if(enoughPay(p.money,equ1.cost)) {
			    System.out.println("You buy the "+equ1.equ_name);
		    	System.out.println("==========================");
		    	useEqu(equ1.speed,equ1.Acceleration);
		    	p.money-=equ1.cost;
		    	break;
		   }
		   else {
			   System.out.println("You can't buy the "+equ1.equ_name);
			   System.out.println("==========================");
			   break;
		   }
		   
		  case(2):
		   if(enoughPay(p.money,equ2.cost)) {
			    System.out.println("You buy the "+equ2.equ_name);
		    	System.out.println("==========================");
		    	p.money-=equ2.cost;
		    	useEqu(equ2.speed,equ2.Acceleration);
		    	break;
		   }
		   else {
			   System.out.println("You can't buy the "+equ2.equ_name);
			   System.out.println("==========================");
			   break;
		   }
		   
		  case(3):
		   if(enoughPay(p.money,equ3.cost)) {
			   System.out.println("You buy the "+equ3.equ_name);
			   System.out.println("==========================");
			   useEqu(equ3.speed,equ3.Acceleration);
			   p.money-=equ3.cost;
		    break;
		   }
		   else {
			   System.out.println("You can't buy the "+equ3.equ_name);
			   System.out.println("==========================");
		    break;
		   }  
		  }
		 }while(select_equ!=4);
		  int random = (int)(Math.random()*3)+1;
		 do {
		  random = (int)(Math.random()*3)+1;
		  switch(random) {
		  case(1):
		   if(enoughPay(c.money,equ1.cost)) {
			   System.out.println("Computer buy the "+equ1.equ_name);
			   useEqu(equ1.speed,equ1.Acceleration);
			   c.money-=equ1.cost;
		    break;
		   }
		   else {
		    break;
		   }
		   
		  case(2):
		   if(enoughPay(c.money,equ2.cost)) {
			   System.out.println("Computer buy the "+equ2.equ_name);
			   useEqu(equ2.speed,equ2.Acceleration);
			   c.money-=equ2.cost;
		    break;
		   }
		   else {
		    break;
		   }
		   
		  case(3):
		   if(enoughPay(c.money,equ3.cost)) {
			   	System.out.println("Computer buy the "+equ3.equ_name);
			    useEqu(equ2.speed,equ2.Acceleration);
			    c.money-=equ2.cost;
			    break;
		   }
		   else{
			    break;
			   }
		  }
		 }while(enoughPay(c.money,equ1.cost)||enoughPay(c.money,equ2.cost)||enoughPay(c.money,equ3.cost));
		}
	}
	
	
	
	@Override
	void startPlay() {
	 // TODO Auto-generated method stub
		c.ans = 0;
		p.ans = 0;
		String player1 = "player1--                        |||||||";
		String player2 = "|||||||                        --player2";
		int p1=p.speed*5;
		int p2=c.speed*5;
		int i;
		System.out.println(c.speed);
		if(p.shotPoint+c.shotPoint==0) {
			System.out.println("=========================game1======================");
		}
		else if (p.shotPoint+c.shotPoint==1) {
			System.out.println("=========================game2======================");
		}
		else if (p.shotPoint+c.shotPoint==2) {
			System.out.println("=========================game3======================");
		}
		System.out.println(player1);
		System.out.println(player2);
		System.out.println("======================================================");
		do{
			if(p1+5*p.Acceleration > distance) {
				player1 = "player1                        --|||||||||";
				System.out.println(player1);
			}else {
				System.out.print("player1");
				for(i=0;i<p1;i+=5) {
					System.out.print(" ");
				}
				System.out.print("--");
				for(i=p1;i<distance;i+=5) {
					System.out.print(" ");
				}
				System.out.println("|||||||");
			}
			if(p2+5*c.Acceleration > distance) {
				player1 = "|||||||--                        computer";
				System.out.println(player1);
			}else {
				System.out.print("|||||||");
				for(i=p2;i<distance;i+=5) {
					System.out.print(" ");
				}
				System.out.print("--");
				for(i=0;i<p2;i+=5) {
					System.out.print(" ");
				}
				System.out.println("computer");
			}
			System.out.println("======================================================");
			p1+=p.Acceleration*5;
			p2+=c.Acceleration*5;
		}while(p1 <= distance && p2 <= distance);
		matchset(p1,p2);
	}
	void matchset(int player, int computer) {
		if(player>computer) {
			p.shotPoint++;
			p.ans = 1;
			System.out.println("========================================================================================================================================================");
			System.out.println("===============================================================        the winner is   player      =====================================================");
			System.out.println("========================================================================================================================================================");
		}else if(player == computer) {
			System.out.println("========================================================================================================================================================");
			System.out.println("===============================================================        no winner      ==================================================================");
			System.out.println("========================================================================================================================================================");
		}
		else {
			c.shotPoint++;
			c.ans = 1;
			System.out.println("========================================================================================================================================================");
			System.out.println("===============================================================        the winner is   computer      ===================================================");
			System.out.println("========================================================================================================================================================");
		}
	}
}