package br.com.novatec.SistemaVendas.Controllers;




import br.com.novatec.SistemaVendas.Entities.Venda;
import br.com.novatec.SistemaVendas.Repositories.SistemaVendasRepositoryVenda;
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
public class VendaController {
    SistemaVendasRepositoryVenda repository;
        
    @GetMapping("/venda")
    public List<Venda> getAllVendas(){
        return repository.findAll();
    }
    @GetMapping("/venda/{id}")  
    public Object getVendaById(@PathVariable Long id){
        return repository.findById(id).get();
    }
    @PostMapping("/venda")
    public Venda saveVenda(@RequestBody Venda venda){
        return repository.save(venda);
    }
    @DeleteMapping("venda/{id}")
    public void deleteVenda(@PathVariable Long id){
        repository.deleteById(id);
    }
    
}
