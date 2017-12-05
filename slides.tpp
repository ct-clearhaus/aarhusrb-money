--## Show slides:
--## $ docker build -t tpp .
--## $ docker run --rm -it -v $PWD/slides.tpp:/s tpp s

--author Casper Thomsen
--title RubyMoney
--center Currencies are crazy


--date 2017-12-04

--newpage RubyMoney
--heading RubyMoney

Project

Gem                Comment
================   =========================
money              Money
money-rails        For rails, dunno 'bout it
monetize           Make stuff into Money
google_currency    Use Google for FX
eu_central_bank    Use ECB for FX; you shouldn't(*)
money-heuristics   Dunno, we need to be sure

(*): http://www.ecb.europa.eu/press/pr/date/2015/html/pr151207.en.html

--newpage money
--heading RubyMoney/money

* It's a gem

* Usage: https://github.com/RubyMoney/money#usage
---

* Changes to config/currency_iso.json the last 12 months?
---
--huge       too  many
--center 11

https://github.com/RubyMoney/money/commits/master/config/currency_iso.json

--newpage diffs
--heading Interresting ones?

https://github.com/RubyMoney/money/commit/7552ed68d563c169093676476142f36b6607ff47#diff-1997e01f8ad8bb743e2b20aa84229c49

-    "subunit_to_unit": 100,
+    "subunit_to_unit": 1,

What's this?

---
                 Money.new(100, :dkk)
---
            BEFORE                   AFTER
         1 DKK coin               100 DKK note


--newpage CLP
--heading CLP - Chilean Peso
--center A real change!

ISO: duly signed ...
---
--huge                      fax
https://www.currency-iso.org/dam/isocy/downloads/dl_currency_iso_amendment_92.pdf

CLP: Change exponent to 0

Dated:     1996-10-07
---
Effective: 1996-05-31    WTF?

--newpage CLP-card-schemes
--heading CLP - what about card schemes?

---

--huge /ignore

---

Until recently ...
    http://docs.gateway.clearhaus.com/#clp-and-ugx-exponent-changes
    https://github.com/RubyMoney/money/pull/727#issuecomment-332751592


--newpage wanted
--heading Wanted!

* "tz database for currencies" (https://en.wikipedia.org/wiki/Tz_database)
  Include different perceptions:
    * ISO
    * The currency's central bank
    * Visa
    * Mastercard
    * ECB
    * ...
---

* Gem that uses this
---

* Allows custom overrides and a custom perception

--newpage proposal
--heading API proposal

  * example-1.rb

  * example-2.rb

--newpage extras
--heading Extras

CLF changed exponent from 0 to 4 in 2014:
https://www.currency-iso.org/dam/isocy/downloads/dl_currency_iso_amendment_157.pdf

---
Ian, working remote for Clearhaus:

---
> Huh, I didn't know CLF changed to exponent 4
---
> It's represented with 2 everywhere :-D
---
> We just recently started dropping 1 and 5 CLP coin
---
--huge         :facepalm:
