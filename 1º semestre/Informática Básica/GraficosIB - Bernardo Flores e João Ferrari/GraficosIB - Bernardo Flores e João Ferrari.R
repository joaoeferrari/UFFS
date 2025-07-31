library(ggplot2)
data("economics")
str(economics)
summary(economics)
grafico=ggplot(economics,aes(x=date, y=unemploy,))+
  labs(x = 'Anos', y = 'Número de Desempregados', title="Série Temporal Economica dos E.U.A.")+
  
  
  geom_area()

grafico2=ggplot(economics,aes(x=date, y=pce, ))+
  labs(title='Série Temporal Economica dos E.U.A.', x = 'Anos', y = 'Despesas de Consumo Pessoal')+
  
  geom_line()

grafico3=ggplot(economics,aes(x=date, y=pop, ))+
  labs(title='Série Temporal Economica dos E.U.A.', x = 'Anos', y = 'População')+
  
  geom_violin()