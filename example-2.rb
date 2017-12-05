m = Money.new(100_00, 2, 'CLP', Time.parse('2017-10-13T11:32:19+00:00'))

m.perception(:visa, Time.now)
#=> SomeError: Too high precision, exponent must be 0

m.perception(:mastercard, Time.now)
#=> <#PerceptedMoney amount:10000 exponent:2 currency:CLP>
