find . -name "*.out" | xargs -I{} rm {}
find . -name "*~" | xargs -I{} rm {}
