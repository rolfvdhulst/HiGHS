/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                       */
/*    This file is part of the HiGHS linear optimization suite           */
/*                                                                       */
/*    Written and engineered 2008-2021 at the University of Edinburgh    */
/*                                                                       */
/*    Available as open-source under the MIT License                     */
/*                                                                       */
/*    Authors: Julian Hall, Ivet Galabova, Qi Huangfu, Leona Gottwald    */
/*    and Michael Feldmeier                                              */
/*                                                                       */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**@file lp_data/HStruct.h
 * @brief Structs for HiGHS
 */
#ifndef LP_DATA_HSTRUCT_H_
#define LP_DATA_HSTRUCT_H_

#include <vector>

#include "lp_data/HConst.h"

struct HighsIterationCounts {
  HighsInt simplex = 0;
  HighsInt ipm = 0;
  HighsInt crossover = 0;
  HighsInt qp = 0;
};

struct HighsSolution {
  bool value_valid = false;
  bool dual_valid = false;
  std::vector<double> col_value;
  std::vector<double> col_dual;
  std::vector<double> row_value;
  std::vector<double> row_dual;
};

struct RefactorInfo {
  bool valid = false;
  std::vector<HighsInt> pivot_row;
  std::vector<HighsInt> pivot_var;
  std::vector<int8_t> pivot_type;
  double build_synthetic_tick;
  void clear();
  void get(RefactorInfo& refactor_info) const;
  void set(const RefactorInfo& refactor_info);
  void set(const HighsInt num_col, const HighsInt num_row);
  bool isOk(const HighsInt num_col, const HighsInt num_row) const;
};

struct HighsBasis {
  bool valid = false;
  std::vector<HighsBasisStatus> col_status;
  std::vector<HighsBasisStatus> row_status;
  RefactorInfo refactor_info;
};

struct HighsScale {
  HighsInt strategy;
  bool has_scaling;
  HighsInt num_col;
  HighsInt num_row;
  double cost;
  std::vector<double> col;
  std::vector<double> row;
};

#endif /* LP_DATA_HSTRUCT_H_ */
