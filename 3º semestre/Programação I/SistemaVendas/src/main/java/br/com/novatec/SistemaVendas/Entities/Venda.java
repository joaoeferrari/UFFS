
package br.com.novatec.SistemaVendas.Entities;


import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Entity
@Data
@AllArgsConstructor
@NoArgsConstructor

public class Venda {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    long id;
    String produto;
    String vendedor;
    int quantidade;
    double valor;
    String formaPagamento;
        
   
        
}
