# Podstawy programowania obiektowego

## Synchronizacja repozytorium
```
git pull
```

## Uruchamianie (ręczna kompilacja)
```
cd harmonogram/
g++ -o harmonogram main.cpp czas.cpp
./harmonogram
```

## Uruchamianie (kompilacja z użyciem `make`)
Do tego należy sprawdzić, czy zainstalowany jest program `make`:
```
make --version
```
Jeśli program nie został znaleziony - należy go zainstalować. Następnie:
```
mkdir builds
cd harmonogram/
make
../builds/harmonogram
```
