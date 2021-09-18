import java.util.Random;
public class Rodas{
	boolean calibrado;

	public Rodas(){// Metodo Construtor
		Random r = new Random(); // Criação do objeto tipo Random
		calibrado = r.nextBoolean(); // Atribuição aleatória de um valor booleano para a variável 
	}
	public String toString(){ // retorna o status em string do pneu
		return (calibrado?"Cheio":"Vazio");
	}
	public boolean status(){ //retorna o status do pneu
		return calibrado;
	}
	public void calibrar(){ // Calibra o pneu
		calibrado = true;
	}
	public void esvaziar(){ // Esvazia o pneu
		calibrado = false;
	}
}