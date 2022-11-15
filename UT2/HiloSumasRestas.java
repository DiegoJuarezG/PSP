package ejemplohilos;

public class HiloSumasRestas implements Runnable {
	
	private int numero=1000;
	private int numVeces;
	private String operacion;
	
//Constructor de la clase
	public HiloSumasRestas(int numveces, String operacion)
	{
		this.numVeces=numveces;
		this.operacion=operacion;
	}
	//Incrementará numero el numvece indicado
	public int incrementar (int numveces)
	{
		for(int i=0;i<numveces;i++) {
			numero++;
		}
		return numero;
	}
	//Decrementará numero el numvece indicado
	public int decrementar (int numveces)
	{
		for(int i=numveces;i>0;i--) {
			numero--;
		}
		return numero;
	}
	public void run() {
	//Si la operación es “+” se invocará al método incrementar
	//Si la operación es “-” se invocará al método decrementar
		if(operacion.equals("+")) {
			incrementar(numVeces);
		}
		else if(operacion.equals("-")) {
			decrementar(numVeces);
		}
		else {
			System.out.println("Operacion no valida");
		}
		System.out.println("Numero: "+numero);
	}
}
