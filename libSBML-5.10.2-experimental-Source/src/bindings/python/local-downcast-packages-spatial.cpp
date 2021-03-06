#ifdef USE_SPATIAL
else if (pkgName == "spatial")
{
  switch (sb->getTypeCode() )
  {
    case SBML_LIST_OF:
      name = sb->getElementName();
      if (name == "listOfDomainTypes")
      {
        return SWIGTYPE_p_ListOfDomainTypes;
      }
      else if (name == "listOfDomains")
      {
        return SWIGTYPE_p_ListOfDomains;
      }
      else if (name == "listOfInteriorPoints")
      {
        return SWIGTYPE_p_ListOfInteriorPoints;
      }
      else if (name == "listOfAdjacentDomains")
      {
        return SWIGTYPE_p_ListOfAdjacentDomains;
      }
      else if (name == "listOfGeometryDefinitions")
      {
        return SWIGTYPE_p_ListOfGeometryDefinitions;
      }
      else if (name == "listOfCoordinateComponents")
      {
        return SWIGTYPE_p_ListOfCoordinateComponents;
      }
      else if (name == "listOfSampledVolumes")
      {
        return SWIGTYPE_p_ListOfSampledVolumes;
      }
      else if (name == "listOfAnalyticVolumes")
      {
        return SWIGTYPE_p_ListOfAnalyticVolumes;
      }
      else if (name == "listOfSpatialPoints")
      {
        return SWIGTYPE_p_ListOfSpatialPoints;
      }
      else if (name == "listOfCSGObjects")
      {
        return SWIGTYPE_p_ListOfCSGObjects;
      }
      else if (name == "listOfCSGNodes")
      {
        return SWIGTYPE_p_ListOfCSGNodes;
      }
      else if (name == "listOfCoordinateReferences")
      {
        return SWIGTYPE_p_ListOfCoordinateReferences;
      }

      return SWIGTYPE_p_ListOf;

    case SBML_SPATIAL_DOMAINTYPE:
      return SWIGTYPE_p_DomainType;

    case SBML_SPATIAL_DOMAIN:
      return SWIGTYPE_p_Domain;

    case SBML_SPATIAL_INTERIORPOINT:
      return SWIGTYPE_p_InteriorPoint;

    case SBML_SPATIAL_BOUNDARY:
      return SWIGTYPE_p_Boundary;

    case SBML_SPATIAL_ADJACENTDOMAINS:
      return SWIGTYPE_p_AdjacentDomains;

    case SBML_SPATIAL_GEOMETRYDEFINITION:
      return SWIGTYPE_p_GeometryDefinition;

    case SBML_SPATIAL_COMPARTMENTMAPPING:
      return SWIGTYPE_p_CompartmentMapping;

    case SBML_SPATIAL_COORDINATECOMPONENT:
      return SWIGTYPE_p_CoordinateComponent;

    case SBML_SPATIAL_SAMPLEDFIELDGEOMETRY:
      return SWIGTYPE_p_SampledFieldGeometry;

    case SBML_SPATIAL_SAMPLEDFIELD:
      return SWIGTYPE_p_SampledField;

    case SBML_SPATIAL_IMAGEDATA:
      return SWIGTYPE_p_ImageData;

    case SBML_SPATIAL_SAMPLEDVOLUME:
      return SWIGTYPE_p_SampledVolume;

    case SBML_SPATIAL_ANALYTICGEOMETRY:
      return SWIGTYPE_p_AnalyticGeometry;

    case SBML_SPATIAL_ANALYTICVOLUME:
      return SWIGTYPE_p_AnalyticVolume;

    case SBML_SPATIAL_PARAMETRICGEOMETRY:
      return SWIGTYPE_p_ParametricGeometry;

    case SBML_SPATIAL_PARAMETRICOBJECT:
      return SWIGTYPE_p_ParametricObject;

    case SBML_SPATIAL_POLYGONOBJECT:
      return SWIGTYPE_p_PolygonObject;

    case SBML_SPATIAL_SPATIALPOINT:
      return SWIGTYPE_p_SpatialPoint;

    case SBML_SPATIAL_CSGEOMETRY:
      return SWIGTYPE_p_CSGeometry;

    case SBML_SPATIAL_CSGOBJECT:
      return SWIGTYPE_p_CSGObject;

    case SBML_SPATIAL_CSGNODE:
      return SWIGTYPE_p_CSGNode;

    case SBML_SPATIAL_CSGTRANSFORMATION:
      return SWIGTYPE_p_CSGTransformation;

    case SBML_SPATIAL_CSGTRANSLATION:
      return SWIGTYPE_p_CSGTranslation;

    case SBML_SPATIAL_CSGROTATION:
      return SWIGTYPE_p_CSGRotation;

    case SBML_SPATIAL_CSGSCALE:
      return SWIGTYPE_p_CSGScale;

    case SBML_SPATIAL_CSGHOMOGENEOUSTRANSFORMATION:
      return SWIGTYPE_p_CSGHomogeneousTransformation;

    case SBML_SPATIAL_TRANSFORMATIONCOMPONENTS:
      return SWIGTYPE_p_TransformationComponents;

    case SBML_SPATIAL_CSGPRIMITIVE:
      return SWIGTYPE_p_CSGPrimitive;

    case SBML_SPATIAL_CSGPSEUDOPRIMITIVE:
      return SWIGTYPE_p_CSGPseudoPrimitive;

    case SBML_SPATIAL_CSGSETOPERATOR:
      return SWIGTYPE_p_CSGSetOperator;

    case SBML_SPATIAL_SPATIALSYMBOLREFERENCE:
      return SWIGTYPE_p_SpatialSymbolReference;

    case SBML_SPATIAL_DIFFUSIONCOEFFICIENT:
      return SWIGTYPE_p_DiffusionCoefficient;

    case SBML_SPATIAL_ADVECTIONCOEFFICIENT:
      return SWIGTYPE_p_AdvectionCoefficient;

    case SBML_SPATIAL_BOUNDARYCONDITION:
      return SWIGTYPE_p_BoundaryCondition;

    case SBML_SPATIAL_GEOMETRY:
      return SWIGTYPE_p_Geometry;

    case SBML_SPATIAL_COORDINATEREFERENCE:
      return SWIGTYPE_p_CoordinateReference;

    default:
      return SWIGTYPE_p_SBase;
  }
}

#endif // USE_SPATIAL 

