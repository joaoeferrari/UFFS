package br.com.novatec.SistemaVendas.Entities;


import jakarta.annotation.Generated;
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

public class Saida {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    long id;
    double valorSaida;
    String descricao;
    
    
}
