<?php
/**
 * @file
 * examsforsale.features.inc
 */

/**
 * Implements hook_default_registration_type().
 */
function examsforsale_default_registration_type() {
  $items = array();
  $items['exam_registration_student_paid'] = entity_import('registration_type', '{
    "name" : "exam_registration_student_paid",
    "label" : "Exam Registration (student paid)",
    "locked" : "0",
    "default_state" : "pending",
    "data" : null,
    "weight" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
