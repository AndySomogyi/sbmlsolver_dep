/**
 * @file:   MultiSpeciesPlugin.cpp
 * @brief:  Implementation of the MultiSpeciesPlugin class
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#include <sbml/packages/multi/extension/MultiSpeciesPlugin.h>
#include <sbml/packages/multi/validator/MultiSBMLError.h>

#include <sbml/util/ElementFilter.h>
#include <sbml/Model.h>


using namespace std;


#ifdef __cplusplus


LIBSBML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new MultiSpeciesPlugin
 */
MultiSpeciesPlugin::MultiSpeciesPlugin(const std::string& uri,  
                                 const std::string& prefix, 
                               MultiPkgNamespaces* multins) :
    SBasePlugin(uri, prefix, multins)
  , mOutwardBindingSites (multins)
  , mSpeciesFeatures (multins)
   ,mSpeciesType ("")
{
}


/*
 * Copy constructor for MultiSpeciesPlugin.
 */
MultiSpeciesPlugin::MultiSpeciesPlugin(const MultiSpeciesPlugin& orig) :
    SBasePlugin(orig)
  , mOutwardBindingSites ( orig.mOutwardBindingSites)
  , mSpeciesFeatures ( orig.mSpeciesFeatures)
{
  if (&orig == NULL)
  {
    mSpeciesType  = orig.mSpeciesType;
  }
}


/*
 * Assignment operator for MultiSpeciesPlugin.
 */
MultiSpeciesPlugin& 
MultiSpeciesPlugin::operator=(const MultiSpeciesPlugin& rhs)
{
  if (&rhs != this)
  {
    this->SBasePlugin::operator=(rhs);
    mOutwardBindingSites = rhs.mOutwardBindingSites;
    mSpeciesFeatures = rhs.mSpeciesFeatures;
    mSpeciesType  = rhs.mSpeciesType;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MultiSpeciesPlugin object.
 */
MultiSpeciesPlugin* 
MultiSpeciesPlugin::clone () const
{
  return new MultiSpeciesPlugin(*this);
}


/*
 * Destructor for MultiSpeciesPlugin.
 */
MultiSpeciesPlugin::~MultiSpeciesPlugin()
{
}


//---------------------------------------------------------------
//
// overridden virtual functions for read/write/check
//
//---------------------------------------------------------------

/*
 * create object
 */
SBase*
MultiSpeciesPlugin::createObject (XMLInputStream& stream)
{
  SBase* object = NULL; 

  const std::string&      name   = stream.peek().getName(); 
  const XMLNamespaces&    xmlns  = stream.peek().getNamespaces(); 
  const std::string&      prefix = stream.peek().getPrefix(); 

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ? xmlns.getPrefix(mURI) : mPrefix;

  if (prefix == targetPrefix) 
  { 
    MULTI_CREATE_NS(multins, getSBMLNamespaces());
    if (name == "listOfOutwardBindingSites" ) 
    { 
      object = &mOutwardBindingSites;

      if (targetPrefix.empty() == true) 
      { 
        mOutwardBindingSites.getSBMLDocument()->enableDefaultNS(mURI, true); 
      } 
    } 
    else if (name == "listOfSpeciesFeatures" ) 
    { 
      object = &mSpeciesFeatures;

      if (targetPrefix.empty() == true) 
      { 
        mSpeciesFeatures.getSBMLDocument()->enableDefaultNS(mURI, true); 
      } 
    } 
    delete multins;
  } 

  return object; 
}


/*
 * write elements
 */
void
MultiSpeciesPlugin::writeElements (XMLOutputStream& stream) const
{
  if (getNumOutwardBindingSites() > 0) 
  { 
    mOutwardBindingSites.write(stream);
  } 
  if (getNumSpeciesFeatures() > 0) 
  { 
    mSpeciesFeatures.write(stream);
  } 
}


/*
 * Checks if this plugin object has all the required elements.
 */
bool
MultiSpeciesPlugin::hasRequiredElements () const
{
  bool allPresent = true; 

  // TO DO 

  return allPresent; 
}

  /** @cond doxygenLibsbmlInternal */

/*
 * Get the list of expected attributes for this element.
 */
void
MultiSpeciesPlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  attributes.add("speciesType");
}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
MultiSpeciesPlugin::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  const unsigned int sbmlLevel   = getLevel  ();
  const unsigned int sbmlVersion = getVersion();

  unsigned int numErrs;

  // look to see whether an unknown attribute error was logged
  if (getErrorLog() != NULL)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("multi", MultiUnknownError,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("multi", MultiUnknownError,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
    }
  }

  bool assigned = false;

  //
  // speciesType SIdRef   ( use = "optional" )
  //
  assigned = attributes.readInto("speciesType", mSpeciesType);

  if (assigned == true)
  {
    // check string is not empty and correct syntax

    if (mSpeciesType.empty() == true)
    {
      logEmptyString(mSpeciesType, getLevel(), getVersion(), 
        getPackageVersion(), "<MultiSpeciesPlugin>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mSpeciesType) == false && getErrorLog() != NULL)
    {
      getErrorLog()->logError(InvalidIdSyntax, getLevel(), getVersion(), 
        "The syntax of the attribute speciesType='" + mSpeciesType + "' does not conform.");
    }
  }

}


  /** @endcond doxygenLibsbmlInternal */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write values of XMLAttributes to the output stream.
 */
  void
MultiSpeciesPlugin::writeAttributes (XMLOutputStream& stream) const
{
  if (isSetSpeciesType() == true)
    stream.writeAttribute("speciesType", getPrefix(), mSpeciesType);
}


  /** @endcond doxygenLibsbmlInternal */



//---------------------------------------------------------------
//
// Functions for interacting with the members of the plugin
//
//---------------------------------------------------------------


/*
 * Returns the value of the "speciesType" attribute of this SpeciesPlugin.
 */
const std::string&
MultiSpeciesPlugin::getSpeciesType() const
{
  return mSpeciesType;
}


/*
 * Returns true/false if speciesType is set.
 */
bool
MultiSpeciesPlugin::isSetSpeciesType() const
{
  return (mSpeciesType.empty() == false);
}


/*
 * Sets speciesType and returns value indicating success.
 */
int
MultiSpeciesPlugin::setSpeciesType(const std::string& speciesType)
{
  if (&(speciesType) == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (!(SyntaxChecker::isValidInternalSId(speciesType)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSpeciesType = speciesType;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets speciesType and returns value indicating success.
 */
int
MultiSpeciesPlugin::unsetSpeciesType()
{
  mSpeciesType.erase();

  if (mSpeciesType.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}



List*
MultiSpeciesPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_LIST(ret, sublist, mOutwardBindingSites, filter);
  ADD_FILTERED_LIST(ret, sublist, mSpeciesFeatures, filter);

  return ret;
}


/*
 * Returns the ListOfOutwardBindingSites in this plugin object.
 */
const ListOfOutwardBindingSites* 
MultiSpeciesPlugin::getListOfOutwardBindingSites () const
{
  return &this->mOutwardBindingSites;
}


/*
 * Returns the ListOfOutwardBindingSites in this plugin object.
 */
ListOfOutwardBindingSites* 
MultiSpeciesPlugin::getListOfOutwardBindingSites ()
{
  return &this->mOutwardBindingSites;
}


/*
 * Returns the OutwardBindingSite object that belongs to the given index.
 */
const OutwardBindingSite*
MultiSpeciesPlugin::getOutwardBindingSite(unsigned int n) const
{
  return static_cast<const OutwardBindingSite*>(mOutwardBindingSites.get(n));
}


/*
 * Returns the OutwardBindingSite object that belongs to the given index.
 */
OutwardBindingSite*
MultiSpeciesPlugin::getOutwardBindingSite(unsigned int n)
{
  return static_cast<OutwardBindingSite*>(mOutwardBindingSites.get(n));
}


/*
 * Returns the OutwardBindingSite object based on its identifier.
 */
const OutwardBindingSite*
MultiSpeciesPlugin::getOutwardBindingSite(const std::string& sid) const
{
  return static_cast<const OutwardBindingSite*>(mOutwardBindingSites.get(sid));
}


/*
 * Returns the OutwardBindingSite object based on its identifier.
 */
OutwardBindingSite*
MultiSpeciesPlugin::getOutwardBindingSite(const std::string& sid)
{
  return static_cast<OutwardBindingSite*>(mOutwardBindingSites.get(sid));
}


/*
 * Adds a copy of the given OutwardBindingSite to the ListOfOutwardBindingSites in this plugin object.
 */
int
MultiSpeciesPlugin::addOutwardBindingSite (const OutwardBindingSite* outwardBindingSite)
{
  if (outwardBindingSite == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (outwardBindingSite->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != outwardBindingSite->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != outwardBindingSite->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != outwardBindingSite->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    mOutwardBindingSites.append(outwardBindingSite);
  }

  return LIBSBML_OPERATION_SUCCESS;

}


/*
 * Creates a new OutwardBindingSite object and adds it to the ListOfOutwardBindingSites in this plugin object.
 */
OutwardBindingSite* 
MultiSpeciesPlugin::createOutwardBindingSite ()
{
   OutwardBindingSite* obs = NULL;

  try
  {
    MULTI_CREATE_NS(multins, getSBMLNamespaces());
    obs = new OutwardBindingSite(multins);
    delete multins;
  }
  catch(...)
  {
  }

  if (obs != NULL)
  {
    mOutwardBindingSites.appendAndOwn(obs);
  }

  return obs;
}


/*
 * Removes the nth OutwardBindingSite object from this plugin object
 */
OutwardBindingSite* 
MultiSpeciesPlugin::removeOutwardBindingSite(unsigned int n)
{
  return static_cast<OutwardBindingSite*>(mOutwardBindingSites.remove(n));
}


/*
 * Removes the OutwardBindingSite object with the given id from this plugin object
 */
OutwardBindingSite* 
MultiSpeciesPlugin::removeOutwardBindingSite(const std::string& sid)
{
  return static_cast<OutwardBindingSite*>(mOutwardBindingSites.remove(sid));
}


/*
 * Returns the number of OutwardBindingSite objects in this plugin object.
 */
unsigned int 
MultiSpeciesPlugin::getNumOutwardBindingSites () const
{
  return mOutwardBindingSites.size();
}


/*
 * Returns the ListOfSpeciesFeatures in this plugin object.
 */
const ListOfSpeciesFeatures* 
MultiSpeciesPlugin::getListOfSpeciesFeatures () const
{
  return &this->mSpeciesFeatures;
}


/*
 * Returns the ListOfSpeciesFeatures in this plugin object.
 */
ListOfSpeciesFeatures* 
MultiSpeciesPlugin::getListOfSpeciesFeatures ()
{
  return &this->mSpeciesFeatures;
}


/*
 * Returns the SpeciesFeature object that belongs to the given index.
 */
const SpeciesFeature*
MultiSpeciesPlugin::getSpeciesFeature(unsigned int n) const
{
  return static_cast<const SpeciesFeature*>(mSpeciesFeatures.get(n));
}


/*
 * Returns the SpeciesFeature object that belongs to the given index.
 */
SpeciesFeature*
MultiSpeciesPlugin::getSpeciesFeature(unsigned int n)
{
  return static_cast<SpeciesFeature*>(mSpeciesFeatures.get(n));
}


/*
 * Returns the SpeciesFeature object based on its identifier.
 */
const SpeciesFeature*
MultiSpeciesPlugin::getSpeciesFeature(const std::string& sid) const
{
  return static_cast<const SpeciesFeature*>(mSpeciesFeatures.get(sid));
}


/*
 * Returns the SpeciesFeature object based on its identifier.
 */
SpeciesFeature*
MultiSpeciesPlugin::getSpeciesFeature(const std::string& sid)
{
  return static_cast<SpeciesFeature*>(mSpeciesFeatures.get(sid));
}


/*
 * Adds a copy of the given SpeciesFeature to the ListOfSpeciesFeatures in this plugin object.
 */
int
MultiSpeciesPlugin::addSpeciesFeature (const SpeciesFeature* speciesFeature)
{
  if (speciesFeature == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (speciesFeature->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != speciesFeature->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != speciesFeature->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != speciesFeature->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    mSpeciesFeatures.append(speciesFeature);
  }

  return LIBSBML_OPERATION_SUCCESS;

}


/*
 * Creates a new SpeciesFeature object and adds it to the ListOfSpeciesFeatures in this plugin object.
 */
SpeciesFeature* 
MultiSpeciesPlugin::createSpeciesFeature ()
{
   SpeciesFeature* sf = NULL;

  try
  {
    MULTI_CREATE_NS(multins, getSBMLNamespaces());
    sf = new SpeciesFeature(multins);
    delete multins;
  }
  catch(...)
  {
  }

  if (sf != NULL)
  {
    mSpeciesFeatures.appendAndOwn(sf);
  }

  return sf;
}


/*
 * Creates a new SpeciesFeature object and adds it to the ListOfSpeciesFeatures in this plugin object.
 */
ListOfSpeciesFeatures* 
MultiSpeciesPlugin::createSubListOfSpeciesFeatures ()
{
   ListOfSpeciesFeatures* losf = NULL;

  try
  {
    MULTI_CREATE_NS(multins, getSBMLNamespaces());
    losf = new ListOfSpeciesFeatures(multins);
    delete multins;
  }
  catch(...)
  {
  }

  if (losf != NULL)
  {
    mSpeciesFeatures.addSubListOfSpeciesFeatures(losf);
    //static_cast<ListOfSpeciesFeatures*>(losf)->setIsSubList();
    //mSpeciesFeaturesmSubListOfSpeciesFeatures->add(losf);
  }

  return losf;
}


/*
 * Removes the nth SpeciesFeature object from this plugin object
 */
SpeciesFeature* 
MultiSpeciesPlugin::removeSpeciesFeature(unsigned int n)
{
  return static_cast<SpeciesFeature*>(mSpeciesFeatures.remove(n));
}


/*
 * Removes the SpeciesFeature object with the given id from this plugin object
 */
SpeciesFeature* 
MultiSpeciesPlugin::removeSpeciesFeature(const std::string& sid)
{
  return static_cast<SpeciesFeature*>(mSpeciesFeatures.remove(sid));
}


/*
 * Returns the number of SpeciesFeature objects in this plugin object.
 */
unsigned int 
MultiSpeciesPlugin::getNumSpeciesFeatures () const
{
  return mSpeciesFeatures.size();
}


//---------------------------------------------------------------


/*
 * Set the SBMLDocument.
 */
void
MultiSpeciesPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  mOutwardBindingSites.setSBMLDocument(d);
  mSpeciesFeatures.setSBMLDocument(d);
}


/*
 * Connect to parent.
 */
void
MultiSpeciesPlugin::connectToParent(SBase* sbase)
{
  SBasePlugin::connectToParent(sbase);

  mOutwardBindingSites.connectToParent(sbase);
  mSpeciesFeatures.connectToParent(sbase);
}


/*
 * Enables the given package.
 */
void
MultiSpeciesPlugin::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix, bool flag)
{
  mOutwardBindingSites.enablePackageInternal(pkgURI, pkgPrefix, flag);
  mSpeciesFeatures.enablePackageInternal(pkgURI, pkgPrefix, flag);
}


/*
 * Accept the SBMLVisitor.
 */
bool
MultiSpeciesPlugin::accept(SBMLVisitor& v) const
{
  const Model * model = static_cast<const Model * >(this->getParentSBMLObject());

  v.visit(*model);
  v.leave(*model);

  for(unsigned int i = 0; i < getNumOutwardBindingSites(); i++)
  {
    getOutwardBindingSite(i)->accept(v);
  }

  for(unsigned int i = 0; i < getNumSpeciesFeatures(); i++)
  {
    getSpeciesFeature(i)->accept(v);
  }

  return true;
}




LIBSBML_CPP_NAMESPACE_END


#endif /* __cplusplus */


