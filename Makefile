CXX := g++

TARGET := fo

BUILD_DIR := ./build
SRC_DIR := ./src
INC_DIR := ./include

SRC_CXX := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_CXX := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o,$(SRC_CXX))
# 可简写为
# OBJ_CXX := $(SRC_CXX:$(SRC_DIR)%.cpp=$(BUILD_DIR)/%.o)

INC_FLAGS := $(addprefix -I ,$(INC_DIR))
CXX_FLAGS := -std=c++23 -Wall $(INC_FLAGS)

$(BUILD_DIR)/$(TARGET) : $(OBJ_CXX)
	$(CXX) -o $@ $^
# Pattern Rules
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXX_FLAGS)
# 个人理解是
# 1. $(BUILD_DIR)/$(TARGET) : $(OBJ_CXX) 执行时先发现依赖 ./build/implement.o
# 2. 寻找合适的 rule，这里找到 $(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
# 3. $(BUILD_DIR)/%.o 匹配得出 % = implement
# 4. 且得出的 $(SRC_DIR)/%.cpp = ./src/implemet.cpp 是一个存在的文件
# 5. 如果只删除 $(BUILD_DIR)/ 改成 %.o，% = ./build/implement.o，就不对了
# 6. 因为这样的话，依赖的 $(SRC_DIR)/%.cpp 就是一个不存在的文件了

.PHONY: clean
RM := del
clean:
	$(RM) build\\*.o
	$(RM) build\\*.exe
