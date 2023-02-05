set(NAME dot)
set(TYPE module)
set(INCLUDE_DIR "include/dot")
set(SRC_DIR "src")

set(HEADERS
    ${INCLUDE_DIR}/attribute_map.h
    ${INCLUDE_DIR}/edge.h
    ${INCLUDE_DIR}/graph.h
    ${INCLUDE_DIR}/node.h
)
 
set(SOURCES
    ${SRC_DIR}/attribute_map.cpp
    ${SRC_DIR}/edge.cpp
    ${SRC_DIR}/graph.cpp
    ${SRC_DIR}/node.cpp
)

make_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${DOT_VERSION}
    WARNINGS WERROR
    HEADERS "${HEADERS}"
    SOURCES "${SOURCES}"
)

install_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${DOT_VERSION}
    HEADERS "${HEADERS}"
)