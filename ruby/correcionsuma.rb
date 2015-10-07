#!/usr/bin/env ruby
# correcionsuma.rb
#Suma dos número introducidos por el usuario

require 'highline/import'

def suma(op1, op2)
	op1.to_i + op2.to_i
end

def entrada(numero)
	print "Operando #{numero.to_s}: "
	gets.to_i
end

op1 = entrada(1)
op2 = entrada(2)

puts "#{ op1 } + #{ op2 } = #{ suma(op1, op2) }"