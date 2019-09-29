set(mainsource main.cpp force.cpp print.cpp verlet.cpp)
add_executable(md.exe ${mainsource})
install(TARGETS md.exe DESTINATION bin)



