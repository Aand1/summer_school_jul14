/* XBoost: Ada-Boost and Friends on Haar/ICF/HOG Features, Library and ToolBox
 *
 * Copyright (c) 2008-2014 Paolo Medici <medici@ce.unipr.it>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "factory/register.h"

// Feature Level Classifier
#include "Classifier/BayesianStump.h"
#include "Classifier/NaiveDecisionStump.h"
#include "Classifier/SimpleDecisionStump.h"


// Strong Learner
#include "Classifier/BoostClassifier.h"
#include "Classifier/SoftCascade.h"
#include "Classifier/DecisionTree.h"

// High Level Classifier
#include "Classifier/BinaryClassifier.h"
#include "Classifier/RealDecisionStump.h"
#include "Classifier/RealToDiscrete.h"

// A collection of precomputed classifier
#include "HaarClassifiers.h"
#include "IchnClassifiers.h"

#include "factory/ImageClassifierWrapper.h"
#include "factory/ObjectDetectorWrapper.h"


template<class _I, class _P>
bool register_default_classifier()
{
  return register_classifier_factory_wrapper< ImageClassifierWrapper< _I, _P >, ObjectDetectorWrapper< _I, _P >  >();
}

// register some classifier
static bool _rds2 = register_default_classifier< BoostClassifier< IchnClassifier>, IntegralChannelImagePreprocessor >();
static bool _sds2 = register_default_classifier< SoftCascadeClassifier< IchnClassifier>, IntegralChannelImagePreprocessor >();

static bool _rr1 = register_default_classifier< BoostClassifier< HaarClassifier>, IntegralImagePreprocessor >();
static bool _rr1r = register_default_classifier< BoostClassifier< RealHaarClassifier>, IntegralImagePreprocessor >();
static bool _rr2 = register_default_classifier< SoftCascadeClassifier< HaarClassifier>, IntegralImagePreprocessor >();

static bool _rdc1 = register_default_classifier< BoostClassifier< DecisionTree< HaarFeature > >, IntegralImagePreprocessor >();
static bool _rdc2 = register_default_classifier< BoostClassifier< DecisionTree< IntegralChannelFeature > >, IntegralChannelImagePreprocessor >();
// TODO: if used in a static library develop a _init() method


int frameidx = 0;
