list(APPEND PolyhedralMesh_headers ${CMAKE_CURRENT_SOURCE_DIR}/PolyhedralMesh.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Input.hpp)
list(APPEND PolyhedralMesh_sources ${CMAKE_CURRENT_SOURCE_DIR}/PolyhedralMesh.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Input.cpp)

list(APPEND PolyhedralMesh_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(PolyhedralMesh_sources ${PolyhedralMesh_sources} PARENT_SCOPE)
set(PolyhedralMesh_headers ${PolyhedralMesh_headers} PARENT_SCOPE)
set(PolyhedralMesh_includes ${PolyhedralMesh_includes} PARENT_SCOPE)
