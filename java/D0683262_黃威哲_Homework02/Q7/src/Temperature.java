
public class Temperature {
	private float num;
	private char scale;
	Temperature(){
	}
	Temperature(char scale,float num){
		this.num = num;
		this.scale = scale;
	}
	Temperature(float num){
		this.num = num;
	}
	Temperature(char scale){
		this.scale = scale;
	}
	public float getDegreeC() {
		if(scale == 'C') {
			return num;
		}else {
			return 5f*(num-32f)/9f;
		}
	}
	public float getDegreeF() {
		if(scale == 'F') {
			return num;
		}else {
			return (9*(num/5))+32f;
		}
	}
	public void setDegree(float degree) {
		this.num = degree;
	}
	public void setScale(char scale) {
		this.scale = scale;
	}
	public void setScaleAndDegree(char scale,float degree) {
		this.scale = scale;
		this.num = degree;
	}
	public boolean equals(Temperature other) {
		if(scale == other.scale) {
			return num == other.num;
		}else {
			if(scale == 'C') {
				return (9*(num/5))+32f == other.num;
			}else {
				return  5f*(num-32f)/9f == other.num;
			}
		}
	}
	public boolean greater(Temperature other){
		if(scale == other.scale) {
			if(num > other.num) return true;
		}else {
			if(scale == 'C') {
				if((9*(num/5))+32f > other.num) return true;
			}else {
				if(5f*(num-32f)/9f > other.num) return  true;
			}
		}
		return false;
	}
	public boolean less(Temperature other){
		if(scale == other.scale) {
			if(num < other.num) return true;
		}else {
			if(scale == 'C') {
				if((9*(num/5))+32f < other.num) return true;
			}else {
				if(5f*(num-32f)/9f < other.num) return  true;
			}
		}
		return false;
	}
	public String toString() {
		if(scale == 'C') {
			return num+ " degree C = " + ((9*(num/5))+32f) +" degree F";
		}else {
			return (5f*(num-32f)/9f) + "degree C = " + num + " degree F";
		}
	}
}
