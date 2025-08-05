package br.com.novatec.SistemaVendas.Controllers;

import br.com.novatec.SistemaVendas.Entities.Saida;
import br.com.novatec.SistemaVendas.Repositories.SistemaVendasRepositorySaida;
import java.util.List;
import lombok.AllArgsConstructor;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;


    @RestController
    @AllArgsConstructor
public class SaidaController {
        SistemaVendasRepositorySaida repository;
        
        @GetMapping("/saida")
        public List<Saida> GetAllSaidas(){
            return repository.findAll();
        }
        @GetMapping("/saida/{id}")  
        public Object getSaidaById(@PathVariable long id){
            return repository.findById(id).get();
        }
        @PostMapping("/saida")
        public Saida saveSaida(@RequestBody Saida saida){
            return repository.save(saida);
        }
        @DeleteMapping("/saida")
        public void deleteSaida(@PathVariable Long id){
            repository.deleteById(id);
        }
        

    
}
