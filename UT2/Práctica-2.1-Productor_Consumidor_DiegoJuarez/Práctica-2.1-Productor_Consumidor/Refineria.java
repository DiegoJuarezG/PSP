class Deposito{
	private double litrosDeposito; //Guarda cuantos litros tiene el deposito 
	private boolean disponible=false; //Guarda si el deposito esta vacio(true) o lleno (false)
	
	public synchronized double llenarDepositoCamion() {
		while(!disponible) {
			try {
				wait();//Si el deposito no tiene nada:espera
			} catch (InterruptedException e) {				
				e.printStackTrace();
			}
		}
		disponible = false;
		notify();//Avisa de que el deposito esta lleno 
		
		return litrosDeposito;
	}
	
	
	public synchronized void prodLlenaDep(double litros) {
		while(disponible) {
			try {
				wait();//Si el deposito tiene algo:espera
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		litrosDeposito=litros;	
		disponible=true;
		notify();//Notifica de que tiene algo
	}
}

class Camion extends Thread{
	int numeroCamion;
	Deposito dep;	
	
	public Camion(Deposito dep,int n) {
		this.dep=dep;
		numeroCamion=n;
	}
	
	public void run() {
		double carga=0;
		int suma=0;
		for(int i=0;i<5;i++) {
			//Llama 5 veces al metodo llenarDeposito y guarda el valor en una variable
			carga=dep.llenarDepositoCamion();
			suma+=carga;//Suma los litros para mostrar al final cuanto ha cargado en total
			System.out.println("Camion "+numeroCamion+" carga: "+Math.floor(carga)+" litros.");			
		}
		System.out.println("Camion"+numeroCamion+"=> Volumen Total Recogido = "+suma+" Operación carga finalizada!!");
	}	
	
}

class Productor extends Thread{
	Deposito dep;	
	
	public Productor(Deposito dep) {
		this.dep=dep;
	}
	
	public void run() {
		double litros;
		for(int i=0;i<15;i++) {			
			litros=Math.random()*1000; //Genera un numero aleatorio entre 0 y 1000 
			System.out.println("Productor llena el depósito con => "+Math.floor(litros)+" Litros");
			dep.prodLlenaDep(litros);	
			
			try {
				sleep(200);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

public class Refineria {
	public static void main(String[] args) {
		Deposito dep=new Deposito();
		
		Camion camion1=new Camion(dep, 1);
		Camion camion2=new Camion(dep, 2);
		Camion camion3=new Camion(dep, 3);
		
		Productor productor=new Productor(dep);
		productor.start();
		camion1.start();
		camion2.start();
		camion3.start();
	}
}
