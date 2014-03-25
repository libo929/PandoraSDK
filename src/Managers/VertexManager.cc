/**
 *  @file   PandoraPFANew/Framework/src/Managers/VertexManager.cc
 * 
 *  @brief  Implementation of the vertex manager class.
 * 
 *  $Log: $
 */

#include "Managers/VertexManager.h"

#include "Objects/Vertex.h"

namespace pandora
{

VertexManager::VertexManager() :
    AlgorithmObjectManager<Vertex>()
{
    PANDORA_THROW_RESULT_IF(STATUS_CODE_SUCCESS, !=, this->CreateInitialLists());
}

//------------------------------------------------------------------------------------------------------------------------------------------

VertexManager::~VertexManager()
{
    (void) this->EraseAllContent();
}

//------------------------------------------------------------------------------------------------------------------------------------------

StatusCode VertexManager::CreateVertex(const CartesianVector &vertexPosition, Vertex *&pVertex)
{
    pVertex = NULL;

    try
    {
        if (!m_canMakeNewObjects)
            throw StatusCodeException(STATUS_CODE_NOT_ALLOWED);

        NameToListMap::iterator iter = m_nameToListMap.find(m_currentListName);

        if (m_nameToListMap.end() == iter)
             throw StatusCodeException(STATUS_CODE_NOT_INITIALIZED);

        pVertex = new Vertex(vertexPosition);

        if (NULL == pVertex)
             throw StatusCodeException(STATUS_CODE_FAILURE);

        if (!iter->second->insert(pVertex).second)
             throw StatusCodeException(STATUS_CODE_FAILURE);

        return STATUS_CODE_SUCCESS;
    }
    catch (StatusCodeException &statusCodeException)
    {
        std::cout << "Failed to create vertex: " << statusCodeException.ToString() << std::endl;
        delete pVertex;
        return statusCodeException.GetStatusCode();
    }
}

} // namespace pandora