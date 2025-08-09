create table product (
  code  integer not null constraint pk_prod primary key,
  name  varchar(15) not null,
  qty   integer not null,
  prc   real not null);
--
create table invoice (
  id integer not null constraint pk_nota primary key,
  address varchar(30) not null,
  tax real not null);
--
create table invoiceitems(
  itemid  integer not null,
  invoiceid integer not null,
  codep  integer not null,
  qty    integer not null,
  constraint pk_item primary key (invoiceid,itemid,codep),
  constraint fk_invoice foreign key (invoiceid) references invoice(id),
  constraint fk_prod foreign key (codep) references product(code)
);
