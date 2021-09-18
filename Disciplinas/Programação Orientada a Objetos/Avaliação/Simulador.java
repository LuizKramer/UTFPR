// Luiz Eduardo Caldas Kramer
// R.A: 2199661
import java.util.Scanner;
class Simulador{
	public static void main(String[] args) { 
		Scanner teclado = new Scanner(System.in); // Criação do objeto Teclado
		Veiculo v[] = new Veiculo[20]; // Criação de um vetor de objetos do tipo Veiculo
		int a, j,aux = 0;; // Declaração de variáveis de controle e auxiliar global.
		boolean x;
		for(a=0; a<v.length; a++){ // inicialização do Vetor em que o Id de todos os veículos são declarados como -1
			v[a] = new Veiculo(-1); 
		}

		int item = 0; // Criação e declaração da variável de seleção e indexação 
		Screen.cls(); // Comando para limpar a tela do console 
		while (item != -1){ // Estrutura de repetição para rodar o código até que o usuário decida o contrário			
			Screen.printMenu(); // impressão do Menu de opções
			item = teclado.nextInt(); // Atribuição de um valor lido no teclado para a variavel item
			Screen.cls();
			switch (item){ // estrutura de seleção que usa o valor lido como parametro
				case 1: // Inserir um veículo
					for(int i =0; i< v.length; i++){ // Percorre todo o vetor
						if(v[i].getId() == -1){ // verifica onde não possui um Veículo Valido
							v[i] = new Veiculo(); // Atribui a posição do vetor um objeto com ID aleatório.
							for(j=0; j < v.length; j++){ // Verifica se ja existe o valor do ID gerado dentro do vetor
								if(j!=i){
									if(v[j].getId()== v[i].getId()){
										v[i] = new Veiculo();  //caso exista ele gera outro Veiculo com ID aleatório e repete o processo até que não haja repetidos
										j = 0;
									}
								}
							}		
							System.out.println("O Veiculo id: " + v[i].getId() + " Foi inserido com sucesso \n");
							i = v.length; // caso o processo tenha detectado que já não existe Veiculos repetidos ele forçã a saida da estrutura de repetição
						}
					}
				break;
				case 2: // Remover um veículo
				x = false; // a variável é usada para verificar se o Veiculo existe ou não dentro do vetor
				System.out.println("insira o Id do Veiculo a ser removido:");
						item = teclado.nextInt();		
						for(a=0; a<v.length; a++){ // Procura o valor lido em item no vetor
							if(v[a].getId()== item){
								v[a] = new Veiculo(-1); // Se o valor for for encotrado na posiçaõ do objeto a ser removido um novo objeto com o ID genérico (-1) é atribuido no lugar
								x=true;
								a = v.length; // caso o item tenha sido encontrado a várivel x é definida com true e é encerrada a estrutura de repetição
							}
							else
								x = false; // se em nenhum momento for encontrado o item a variável mantém seu valor
					}
					if(x) // verifica se foi ou não encontrado o objeto dentro do vetor
							System.out.println("O Veiculo id: " + item + " foi removido com sucesso");
						else
							System.out.println("O Veiculo id: "+ item +" Nao existe");
				break;
				case 3: // Abastecer um veículo
					x = false; 
					System.out.println("Lista de Veiculos Disponiveis:\n");
					for(a=0; a<v.length; a++){ // Mostra os objetos presentes no vetor e a sua respectiva quantidade de combustível
						if(v[a].getId()!= -1)
							System.out.println("- id: "+v[a].getId() + " - Quantidade de combustivel: " + v[a].getCombustivel());
					}
					System.out.print("\nId do veiculo a ser abastecido: ");
					item = teclado.nextInt();
					for(a=0;a<v.length;a++){
						if(v[a].getId() == item){
							x = true;
							aux = a;
							a = v.length;							
						}
						else{
							x=false;
						}
					}
					if(x){  // Abastece a quantidade fornecida pelo usuário
						System.out.println("Quantidade a ser abastecida:");
						double quantidade = teclado.nextDouble();						
						v[aux].abastecer(quantidade);
					}
					else
						System.out.println("ID Invalido!");

				break;
				case 4: // Movimentar um Veiculo
					x= false;
					System.out.println("Lista de Veiculos Disponiveis Para movimentacao:");
					for(a=0;a<v.length;a++){ // Apresenta os Veículos Que podem se movimentar dado se há combustível suficiente, se todos os pneus estão calibrados e se o ipva está pago
						if(v[a].getCombustivel() > 0.55 && (v[a].getRodasCalibradas() == 4) && v[a].getIpva()){
							System.out.print(v[a].getId() + " ");
							v[a].setApto(true); // em caso verdadeiro é definido que o veículo está apto para se movimentar
						}else{
							v[a].setApto(false);// em caso falso é definido que o veículo não está apto para se movimentar
						}
					}
					System.out.println("\nMovimentar Veiculo:"); 
					item = teclado.nextInt(); // Seleção de qual veículo deseja ser movientado
					for(a=0;a<v.length;a++){ // Verificação se o Veículo existe
						if(v[a].getId() == item){
							aux = a;
							a=v.length;
							x = true;
						}
					}
					if(x){
						if(v[aux].getApto()){ // Se o Veículo estiver apto para se mover ele anda um "bloco" e atualiza a quantidade de combustível
								v[aux].setDistancia();
								System.out.println("O Veiculo: " + v[aux].getId() + " Foi movimentado com sucesso");
							}
						else // Se o Veículo não estiver apto ele imprime a mensagem de erro mais os dados do veículo para o usuário detectar onde existe a falha
							System.out.println("O Veiculo nao esta apto para se movientar!\n" + v[aux]);				
					}
					else
						System.out.println("Id Invalido! ");
				break;
				case 5: // Mover todos os veículos
					aux =0; // aqui ela atua como contador, se não houver nenhum veículo disponível no vetor é exibida uma mensagem de alerta ao usuário;
					for(a=0;a<v.length;a++){ // Verificação dos veiculos aptos e logo em seguida a movimentação dos Veículos, ou seja, logo após verificar que o Veículo está apto eles já se movimentam
						if((v[a].getCombustivel() > 0.55) && (v[a].getRodasCalibradas() == 4) && (v[a].getIpva())){
							v[a].setApto(true);
							aux++;
						}
						else
							v[a].setApto(false);
						if(v[a].getApto()){ // Movimentação de todos os Veículos
							v[a].setDistancia();
							System.out.println("Veiculo " + v[a].getId() + " Movimentado");
						}
					}
					if(aux == 0)
						System.out.println("Nenhum Veiculo apto para se movientar");
				break;
				case 6: // Imprimir os dados de todos os Veículos
					for(j=0; j<v.length;j++){
						if(v[j].getId() != -1)
							System.out.println(v[j]); // Dentro da classe Veiculo existe o Método toString, por essa razão posso mandar imprimir um tipo Veiculo.
					}

				break;
				case 7: // Esvaziar um pneu específico
					x =false;
					System.out.println("Lista de Veiculos Disponiveis:"); // Mostra a lista dos veículos disponíveis com rodas que podem ser esvaziadas 
						for(a=0; a<v.length; a++){
							if(v[a].getId()!= -1)
							System.out.println("- id: "+v[a].getId() + " - Quantidade de Pneus Cheios: " + v[a].getRodasCalibradas());
						}
					while(!x){ // Enquanto não for inserido um ID válido o programa continuará requisitando o Id do usuário
						System.out.println("Insira o Id do Veiculo:");
						item = teclado.nextInt();
						for(a=0;a<v.length;a++){
							if(v[a].getId() == item){
								x = true;
								aux = a;
								a = v.length;							
							}
							else{
								x=false;
							}
						}
						if(x){
							System.out.println("Status dos pneus do Veiculo: " + v[aux].getId() ); // Mostra o status de cada pneu pertencentes ao Veículo
							v[aux].verificaRodas();
							System.out.println("Pneu a ser esvaziado:");
							item = -1; // Um novo valor é atribuido para poder reutilizar a variável
							while(item >4 || item<0){ // enquanto um valor válido não for lido o valor será requisitado novamente
								item = teclado.nextInt();
								v[aux].esvaziar(item); // função que esvazia o pneu informado
							}
							System.out.println("O pneu numero: "+ v[aux].getId() + " Foi esvaziado\n");

						}
						else{
							System.out.println("Id Invalido!");
						}
					}
				break;
				case 8: // Calibrar um pneu Específico
					x =false; // Mesmo sistema utilizado nos casos 7 e 2
					System.out.println("Lista de Veiculos Disponiveis:");
						for(a=0; a<v.length; a++){
							if(v[a].getId()!= -1)
							System.out.println("- id: "+v[a].getId() + " - Quantidade de pneus Vazios: " + (4 - v[a].getRodasCalibradas()));
						}
					while(!x){ // Enquanto não for inserido um ID válido o programa continuará requisitando o Id do usuário
						System.out.println("Insira o Id do Veiculo:");
						item = teclado.nextInt();
						for(a=0;a<v.length;a++){
							if(v[a].getId() == item){
								x = true;
								aux = a;
								a = v.length;							
							}
							else{
								x=false;
							}
						}
						if(x){
							System.out.println("Status dos pneus do Veiculo: " + v[aux].getId() );
							v[aux].verificaRodas();
							System.out.println("Pneu a ser calibrado:");
							item = -1;
							while(item >4 || item<0){
								item = teclado.nextInt();
								v[aux].calibrar(item); // Função que calibra o pneu Informado
							}
							System.out.println("O pneu numero: "+ v[aux].getId() + " Foi Calibrado\n");

						}
						else{
							System.out.println("Id inserido invalido!");
						}
					}
				break;
				case 9:
					x =false;
					int aux1 = 0;
					System.out.println("Lista de Veiculos Disponiveis:"); // Mostra os veículos que possuem pneus que estão vazios
						for(a=0; a<v.length; a++){
							if(v[a].getId()!= -1 && (v[a].getRodasCalibradas() != 4)){
								System.out.println("- id: "+v[a].getId());
								aux1++; 
							}
						}
					if(aux1>0){	// Verifica se existe ao menos um veículo no vetor
						while(!x){
							System.out.println("Insira o Id do Veiculo:");
							item = teclado.nextInt();
							for(a=0;a<v.length;a++){
								if(v[a].getId() == item){
									x = true;
									aux = a;
									a = v.length;							
								}
								else{
									x=false;
								}
							}
						}
						if(x){
							v[aux].calibrarTodos(); // função que calibra todos os pneus
							System.out.println("Todos os pneus do Veiculo: " + v[aux].getId() + " Foram Calibrados");
						}
						else
							System.out.println("Id inserido invalido!");
					}
					else
						System.out.println("Nao existem pneus a serem calibrados");
					
				break;
				case 10: //imprime a pista de corrida
					String s[] = new String[4]; // Declaração do vetor de objetos tipo Strings 
					s[0] = ("   ____");
					s[1] = ("__/    |__");
					s[2] = ("| _ _     ```.");
					s[3] = ("`-(_)---(_)--`");
					for(a=0; a<v.length;a++){// impressão da posição do Veículo na pista de corrida
						if(v[a].getDistancia()>0){
							System.out.println("Veiculo: " + v[a].getId()); // imprime o Id do veículo e logo em seguida sua posição
							for(int i=0;i<4;i++){ // Imprime cada parte do Veículo separadamente
								for(j=0; j< v[a].getDistancia()/10; j++)
									System.out.print("  ");
								System.out.println(s[i]);
							}
						}
					}
				break;
				case 11: // Sair da aplicação
					Screen.cls(); // a tela do Console é limpa
					item = -1; //Valor para que se encerre a estrutura de repetição do menu
				break;
			}
			
		}

	}

}