import java.util.Random;
public class Veiculo{
	private int id;
	private int distanciaPercorrida;
	private double combustivel;
	private boolean ipva;
	private Rodas r[] = new Rodas[4];
	private boolean apto;

	// Em todos os métodos construtores o IPVA e o ID são gerados pelo objeto Random();
	public Veiculo(){ // Metodo construtor 1
		Random x = new Random();
		id = 1 + x.nextInt(20);
		distanciaPercorrida = 0;
		combustivel = 3.5;
		ipva = x.nextBoolean();
		apto = false;
		for(int a=0; a<r.length;a++) // Define a criação das rodas e seu status (vazia ou cheuia), pelo metodo construtor presente no objeto Rodas;
			r[a] = new Rodas();
	}
	public Veiculo(int id){ // Metodo construtor 2
		this.id = id;
		distanciaPercorrida = 0;
		combustivel = 3.5;
		ipva = false;
		apto = false;
		for(int a=0; a<r.length;a++)
			r[a] = new Rodas();
	}
	public Veiculo(int id, double combustivel){ // Metodo construtor 3
		this.id = id;
		distanciaPercorrida = 0;
		this.combustivel = combustivel;
		ipva = false;
		apto = false;
		for(int a=0; a<r.length;a++)
			r[a] = new Rodas(); 
	}

	public int getId(){ // retorna o ID referente do veículo
		return id;
	}
	public double getCombustivel(){  // retorna o valor de combustivel
		return combustivel;
	}

	public String toString(){	// Retorna os valores das váriaveis pertencentes ao objeto Veiculo
		return "Id: "+ id + " - Distancia Percorrida: " + distanciaPercorrida + " - Quantidade de combustivel: " + combustivel +"L - IPVA pago: "+ (ipva?"sim":"nao") + "\n" + (getRodasCalibradas()==4?"Todas as rodas Calibradas":"Faltam "+ (4-getRodasCalibradas()) + " pneus a serem Calibrados" )+"\n";
	}
	public void verificaRodas(){ // Retorna o Status de cada Roda pertencente ao Veiculo
		for(int a=0; a<r.length;a++){
			System.out.println("Pneu "+ a+ " : " + r[a]);

		}
	}
	public void abastecer(double quantidade){	// Abastece o Veiculo
		System.out.println(quantidade);
		if(combustivel == 3.5) // Verifica se o tanque do Veículo já está cheio
			System.out.println("\nO tanque ja esta cheio");
		else{
			if((quantidade + combustivel) <= 3.5){ // Verifica se a quantidade fornecida pelo usuário é inferior a capacidade do tanque, caso seja ele adiciona o valor, caso contrário ele simplesmente enche o tanque.
				combustivel = quantidade + combustivel;
				System.out.println("O tanque esta com " + combustivel + "L de combustivel");
			}
			else{
				combustivel = 3.5;
				System.out.println("O Tanque foi cheio" + "\n Quantidade no tanque:" + combustivel);
			}
		}
	}
	public void setCombustivel(double quantidade){ // define a quantidade de combustivel do veículo. Nota: utilizei para testes
		combustivel = quantidade;
	}
	public void calibrar(int a){ // Calibra o Pneu informado pelo usuário
		r[a].calibrar();
	}
	public void esvaziar(int a){ // Esvazi o Pneu informado pelo usiário
		r[a].esvaziar();
	}
	public void calibrarTodos(){ // Calibra todos os pneus do veículo
		for(int a=0; a<4; a++)
			r[a].calibrar();
	}
	public int getRodasCalibradas(){ // Retorna a quantidade de rodas calibradas que o veículo possui.
		int i=0;
		int a;
		for(a=0;a<4;a++){
			if(r[a].status())
				i++;
		}
		return i;
	}
	public boolean getIpva(){ // retorna o status do IPVA do veículo. Se está pago ou não;
		return ipva;
	}
	public void setApto(boolean apto){ // Define se o veículo está apto ou não para se locomover
		this.apto = apto;
	}
	public boolean getApto(){ // Retorna o status de aptidão para a locomoção do Veículo
		return apto;
	}
	public void setDistancia(){ // Ele aumenta a distância do Veículo e diminui a quantidade de combustível.
		distanciaPercorrida += 10;
		combustivel -= 0.55;
	}
	public double getDistancia(){ // Retorna a distância Percorrida pelo veículo.
		return distanciaPercorrida;
	}

}