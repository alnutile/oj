<?php

/**
 * Implements hook_default_rules_configuration().
 */
function oj_rules_default_rules_configuration() {
  $items = array();
  $items['rules_make_node_for_purchase_level'] = entity_import('rules_config', '{ "rules_make_node_for_purchase_level" : {
    "LABEL" : "Make node for purchase level",
    "PLUGIN" : "reaction rule",
    "TAGS" : [ "Membership" ],
    "REQUIRES" : [ "uc_order", "php", "rules" ],
    "ON" : [ "uc_order_status_update" ],
    "IF" : [
      { "uc_order_condition_order_state" : { "order" : [ "updated-order" ], "order_state" : "completed" } },
      { "uc_order_condition_has_products" : {
          "order" : [ "order" ],
          "products" : { "value" : { "ten_nodes" : "ten_nodes" } },
          "required" : 1,
          "forbidden" : 0
        }
      }
    ],
    "DO" : [ { "php_eval" : { "code" : "og_add_nodes_for_user($order);\r\n" } } ]
  }
}');

return $items;

}