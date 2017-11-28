NAME=Tarea3
BUILD_PATH=build
BIN_PATH=$(BUILD_PATH)/bin
JAR_PATH=$(BUILD_PATH)/jar

main: clean

funciones:
	mkdir -p $(BIN_PATH)
	javac src/Funciones/*.java	 -d $(BIN_PATH)
	mkdir -p build/jar/
	jar cfm $(JAR_PATH)/$(NAME).jar manifest -C $(BIN_PATH) .
	java -jar $(JAR_PATH)/$(NAME).jar
	rm -rf $(BUILD_PATH)

matrices:
	mkdir -p $(BIN_PATH)
	javac src/Matrices/*.java	 -d $(BIN_PATH)
	mkdir -p build/jar/
	jar cfm $(JAR_PATH)/$(NAME).jar manifest -C $(BIN_PATH) .
	java -jar $(JAR_PATH)/$(NAME).jar
	rm -rf $(BUILD_PATH)

granja:
	mkdir -p $(BIN_PATH)
	javac src/Granja/*.java	 -d $(BIN_PATH)
	mkdir -p build/jar/
	jar cfm $(JAR_PATH)/$(NAME).jar manifest -C $(BIN_PATH) .
	java -jar $(JAR_PATH)/$(NAME).jar
	rm -rf $(BUILD_PATH)

clean:
	rm -rf $(BUILD_PATH)
