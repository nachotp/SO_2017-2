NAME=funciones
BUILD_PATH=build
BIN_PATH=$(BUILD_PATH)/bin
JAR_PATH=$(BUILD_PATH)/jar

classes: src/Funciones/
	mkdir -p $(BIN_PATH)
	javac src/Funciones/*.java	 -d $(BIN_PATH)

jar: classes
	mkdir -p build/jar/
	jar cfm $(JAR_PATH)/$(NAME).jar manifest -C $(BIN_PATH) .

main: jar

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

clean:
	rm -rf $(BUILD_PATH)
