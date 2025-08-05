package br.com.novatec.SistemaVendas.Repositories;


import br.com.novatec.SistemaVendas.SistemaVendasApplication;
import org.springframework.data.jpa.repository.JpaRepository;

import br.com.novatec.SistemaVendas.Entities.Venda;

public interface SistemaVendasRepositoryVenda extends JpaRepository<Venda, Long>{
    
    
}
