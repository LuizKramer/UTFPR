import java.io.IOException;
public class Screen{
	public static void cls() //Metódo para limpara a tela do console.... Peguei do StackOverflow
	{
		try
		{	
			new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor(); 
		}		
		catch(Exception E)
		{
			System.out.println(E);
		}
	}
	public static void printMenu(){ // Imprime o Menu de opções para o usuário
		System.out.println("\n1 - Incluir Veiculo \n2 - Remover Veiculo \n3 - Abastecer Veiculo");
		System.out.println("4 - Movimentar Veiculo\n5 - Movimentar todos os Veiculos\n6 - Imprimir os dados de Todos os Veiculos");
		System.out.println("7 - Esvaziar um pneu especifico\n8 - Calibrar um pneu especifico\n9 - Calibrar todos os Pneus \n10 - Imprimir pista de corrida\n11 - Sair da aplicacao");
	}
	
}
  