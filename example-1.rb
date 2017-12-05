m = Money.new(100, 0, 'CLP', Time.parse('2017-10-13T11:32:19+00:00'))

m.perception(:visa, Time.now)
#=> <#PerceptedMoney amount:100 exponent:0 currency:CLP>

m.perception(:mastercard, Time.now)
#=> <#PerceptedMoney amount:10000 exponent:2 currency:CLP>
