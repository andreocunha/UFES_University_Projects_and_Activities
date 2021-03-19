import java.util.Scanner;

public class Testador {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);        
 
        Empresa empresa = new Empresa();

        empresa.setNome(scan.next());
        empresa.setCNPJ(scan.next());

        int numDepartamentos = scan.nextInt();

        // le todos os dados de cada departamento
        for(int i = 0; i < numDepartamentos; i++){
            Departamento novoDepartamento = new Departamento();
            novoDepartamento.setNome(scan.next());
            int numFuncionarios = scan.nextInt();

            // le todos os dados de cada funcionario do departamento
            for(int j = 0; j < numFuncionarios; j++){
                Funcionario novoFuncionario = new Funcionario();
                novoFuncionario.setNome(scan.next());
                novoFuncionario.setSalario(scan.nextDouble());
                novoFuncionario.setAdmissao(scan.next());
                novoDepartamento.setFuncionarios(novoFuncionario);
            }
            empresa.setDepartamento(novoDepartamento);
        }
        
        Departamento departamento1 = empresa.getDepartamento(0);

        // aumenta o salario de cada funcionario do primeiro departamento
        for(int i = 0; i < departamento1.getQtdFuncionarios(); i++){
            departamento1.getFuncionario(i).aumentarSalario(10);
        }

        // troca o funcionario do departamento 1 para o departamento 2
        Funcionario funcionario1 = departamento1.removeFuncionario(0);
        Departamento departamento2 = empresa.getDepartamento(1);
        departamento2.setFuncionarios(funcionario1);

        // imprime o nome do departamento e a soma dos salarios dos funcionarios
        for(int i = 0; i < empresa.getQtdDepartamentos(); i++){
            Departamento temp = empresa.getDepartamento(i);
            System.out.printf("%s R$ %.2f\n", temp.getNome(), temp.somaDosSalarios());
        }        
        scan.close();
    }
}
